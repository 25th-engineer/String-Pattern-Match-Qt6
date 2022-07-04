#include "batch1.h"
#include "ui_batch1.h"

batch1::batch1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::batch1)
{
    fileInfo = nullptr;
    ui->setupUi(this);
    this->setWindowTitle("Batch Mode 1");
    this->setFixedSize(510, 153); // added

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->comboBox->model());
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QStandardItem * item = model->item(i);
        item->setTextAlignment(Qt::AlignCenter); //Qt::AlignCenter
        item->setSizeHint({ 0, 25});
    }
}

batch1::~batch1()
{
    delete ui;

    delete pattern;
    pattern = NULL;
    delete target;
    target = NULL;
}

void batch1::on_pushButton_clicked()
{
    if(fileInfo != nullptr)
    {
        QString algorithm;
        for(int i = 0;i<fileInfo->count(); i++)
        {
            if(fileInfo->at(i).fileName() == "." || fileInfo->at(i).fileName() == "..")
            {
                continue;
            }
            else
            {
                QString path = fileInfo->at(i).filePath();
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly))
                {
                    return;
                }
                QByteArray data = file.readAll();
                QString testData = QString(data);
                target_s = testData.toStdString();
                tlen = target_s.length();
                target = const_cast<char*>(target_s.c_str());

                QString fileName_t = fileInfo->at(i).fileName();
                if(fileName_t.contains("53x", Qt::CaseInsensitive))
                {
                    pattern_s = "aaaaabbX0698";
                }
                else
                {
                    pattern_s = "fsf8QQCNlL80s1ouGx2TeANoH2jxx9SYQ";
                }
                plen = pattern_s.length();
                pattern = new char(plen);
                pattern = const_cast<char*>(pattern_s.c_str());

                algorithm = ui->comboBox->currentText();
                int index = -1;
                if(!algorithm.compare("BF"))
                {
                    double startTime = (double)clock();
                    BF(index);
                    timeUsedVector.push_back(std::make_pair(fileName_t, (double)clock() - startTime));
                }
                else if(!algorithm.compare("BM"))
                {
                    double startTime = (double)clock();
                    BM(index);
                    timeUsedVector.push_back(std::make_pair(fileName_t, (double)clock() - startTime));
                }
                else if(!algorithm.compare("RK"))
                {
                    double startTime = (double)clock();
                    RK(index);
                    timeUsedVector.push_back(std::make_pair(fileName_t, (double)clock() - startTime));
                }
                else if(!algorithm.compare("KMP"))
                {
                    double startTime = (double)clock();
                    KMP(index);
                    timeUsedVector.push_back(std::make_pair(fileName_t, (double)clock() - startTime));
                }
            }
        }
        std::sort(timeUsedVector.begin(), timeUsedVector.end(), cmpByKeyNum);
        this->close();
        batch1Plot* b1p = new batch1Plot(timeUsedVector, algorithm);
        b1p->show();
        timeUsedVector.clear();
    }
    else
    {
        QMessageBox::about(this, "Operation failed", "Empty fileInfo.\nPlease select a folder first.");
    }

}

void batch1::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory();
    QDir *dir=new QDir(filePath);
    ui->plainTextEdit->setPlainText(filePath);
    QStringList filter;
    fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
}


void batch1::on_pushButton_3_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

bool batch1::BF(int &index)
{
    for(int i = 0; i <= (tlen - plen); i++)
    {
        if(0 == strncmp(target + i, pattern, plen))
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool batch1::RK(int &index)
{
    int tgt = 0;
    for(int i = 0; i < plen; i++)
    {
        tgt += (pattern[i] - ' ');
    }
    int last = 0;
    for(int i = 0; i <= (tlen - plen); i++)
    {
        if(last > 0)
        {
            last = last - (target[i-1] - ' ') + (target[i+plen-1] - ' ');
        }
        else
        {
            for(int j = 0; j < plen; j++)
            {
                last += (target[i+j] - ' ');
            }
        }
        if(last == tgt && 0 == strncmp(target+i, pattern, plen))
        {
            index = i;
            return  true;
        }
    }
    return  false;
}

void batch1::generateBC(int bc[])
{

    for(int i = 0; i < plen; i++)
    {
        bc[(int)pattern[i]] = i;
    }
}

void batch1::generateGS(int suffix[], bool prefix[])
{
    for(int i = 0; i < plen; i++)
    {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for(int i = 0; i < plen - 1; i++)
    {
        int j = i;
        int k = 0;
        while(j >= 0 && pattern[j] == pattern[plen - k - 1])
        {
            k++;
            j--;
            suffix[k] = j + 1;
        }

        if(j == -1)
        {
            prefix[k] = true;
        }
    }
}

int batch1::moveByGS(int j, int suffix[], bool prefix[])
{
    int k = plen - j - 1;   //后缀的长度

    if(suffix[k] != -1)
    {
        return j - suffix[k] + 1;
    }

    for(int i = j + 2; i < plen; i++)
    {
        if(prefix[plen - i])
        {
            return i;
        }
    }

    return plen;
}

bool batch1::BM(int &index)
{
    int bc[128] = {-1};


    generateBC(bc);

    int i = 0;

    int *suffix = new int[plen];
    bool *prefix = new bool[plen];
    generateGS(suffix, prefix);
    while(i < (tlen - plen + 1))
    {
        int j;
        for (j = plen - 1; j >= 0; j--)
        {
            if (target[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j < 0)
        {
            index = i;
            delete []prefix;
            prefix = nullptr;
            delete []suffix;
            suffix = nullptr;
            return true;
        }

        int update = j - bc[(int) target[i+j]];
        if(j < plen - 1)
        {
            int GSupdate = moveByGS(j, suffix, prefix);
            if(GSupdate > update)
            {
                update = GSupdate;
            }
        }

        i += update;
    }
    delete []prefix;
    prefix = nullptr;
    delete []suffix;
    suffix = nullptr;
    return false;
}

void batch1::getNext(int *next)
{
    int plen = strlen(pattern);
    for(int i = 0; i < plen; i++)
    {
        next[i] = -1;
    }

    int j = -1;
    for(int i = 1; i < plen; i++)
    {

        while(j != -1 && pattern[j + 1] != pattern[i])
        {
            j = next[j];
        }
        if(pattern[j + 1] == pattern[i])
        {
            j++;
        }
        next[i] = j;
    }

    /*
    for(int i = 1; i < plen; i++)
    {
        if(next[i - 1] != -1 && pattern[i] == pattern[next[i - 1] + 1])
        {
            next[i] = next[i - 1] + 1;
        }
        else
        {
            int j = 1;
            while(j <= i)
            {

                if(pattern[0] == pattern[j] && 0 == strncmp(pattern, pattern + j, i - j + 1))
                {
                    next[i] = i - j;
                }

                j++;
            }
        }
    }
    */
}

bool batch1::KMP(int &index)
{
    int *next = new int[plen];
    getNext(next);

    int j = 0;
    for(int i = 0; i < tlen; i++)
    {
        while(j > 0 && i > 0 && target[i] != pattern[j])
        {
            j = next[j - 1] + 1;
        }

        if(target[i] == pattern[j])
        {
            ++j;
        }
        if(j == plen)
        {
            index = i - plen  + 1;
            delete []next;
            next = nullptr;
            return true;
        }
    }
    delete []next;
    next = nullptr;
    return false;
}

void batch1::random_string()
{
    srand(time(NULL));

    for(int i = 0; i < tlen; i++)
    {
        int r = rand() % (126 - 64) +64;
        target[i] = (char)r;
    }
    int r = rand() % (tlen - plen + 1);
    r = r % (tlen /2) + tlen / 2;
    strncpy(pattern, target + r, plen);
}

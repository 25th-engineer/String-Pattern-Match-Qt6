#include "batch2.h"
#include "ui_batch2.h"

batch2::batch2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::batch2)
{
    fileInfo = nullptr;
    ui->setupUi(this);
    this->setWindowTitle("Batch Mode 2");
    this->setFixedSize(540, 153); // added
}

batch2::~batch2()
{
    delete ui;
}

void batch2::on_selectFilePushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName();
    ui->plainTextEdit->setPlainText(filePath);
    QFileInfo fileInfo = QFileInfo(filePath);
    fileName = fileInfo.fileName();
}


void batch2::on_executePushButton_2_clicked()
{
    QString path = ui->plainTextEdit->toPlainText();
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray data = file.readAll();
    QString testData = QString(data);
    target_s = testData.toStdString();
    tlen = target_s.length();
    target = const_cast<char*>(target_s.c_str());

    if(fileName.contains("53x", Qt::CaseInsensitive))
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

    int index_1 = -1;
    double startTime = (double)clock();
    BF(index_1);
    timeUsedVector.push_back(std::make_pair(QString("BF"), (double)clock() - startTime));

    int index_2 = -1;
    startTime = (double)clock();
    RK(index_2);
    timeUsedVector.push_back(std::make_pair(QString("RK"), (double)clock() - startTime));


    int index_3 = -1;
    startTime = (double)clock();
    KMP(index_3);
    timeUsedVector.push_back(std::make_pair(QString("KMP"), (double)clock() - startTime));

    int index_4 = -1;
    startTime = (double)clock();
    BM(index_4);
    timeUsedVector.push_back(std::make_pair(QString("BM"), (double)clock() - startTime));

    this->close();
    batch2plot* b2p = new batch2plot(timeUsedVector, fileName);
    b2p->show();
    timeUsedVector.clear();

    timeUsedVector.clear();
}


void batch2::on_startupPushButton_3_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

bool batch2::BF(int &index)
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

bool batch2::RK(int &index)
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

void batch2::generateBC(int bc[])
{

    for(int i = 0; i < plen; i++)
    {
        bc[(int)pattern[i]] = i;
    }
}

void batch2::generateGS(int suffix[], bool prefix[])
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

int batch2::moveByGS(int j, int suffix[], bool prefix[])
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

bool batch2::BM(int &index)
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

void batch2::getNext(int *next)
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

bool batch2::KMP(int &index)
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

void batch2::random_string()
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

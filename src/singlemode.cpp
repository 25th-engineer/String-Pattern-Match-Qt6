#include "singlemode.h"
#include "ui_singlemode.h"
#include "mainwindow.h"
#include <QFileDialog>
#include "patternMatch.h"
#include <QTime>


singlemode::singlemode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::singlemode)
{
    ui->setupUi(this);
    this->setWindowTitle("Single Mode");
    this->setFixedSize(643, 229); // added
    ui->tableWidget->setFixedSize(521, 71); // added
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->plainTextEdit->setReadOnly(true);
    QStringList horizontalHeaders = {"Algorithm", "Test Bench", "Time Used\n(ms)", "Index"};
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaders);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setHidden(true);
    QFont font =  ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    font.setFamily("Times New Roman");
    font.setPointSize(12);
    ui->tableWidget->horizontalHeader()->setFont(font);
    ui->tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableWidget->showGrid();

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->comboBox->model());
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QStandardItem * item = model->item(i);
        item->setTextAlignment(Qt::AlignCenter); //Qt::AlignCenter
        item->setSizeHint({ 0, 25});
    }
}

singlemode::~singlemode()
{
    delete ui;

    delete pattern;
    pattern = NULL;
    delete target;
    target = NULL;
}

void singlemode::on_pushButton_4_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void singlemode::on_pushButton_3_clicked()
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

    QString algorithm = ui->comboBox->currentText();

    for(int i = 0; i < 3; i++)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(fileName));

    int index = -1;
    if(!algorithm.compare("BF"))
    {
        double startTime = (double)clock();
        BF(index);
        double timeUsed = (double)clock() - startTime;
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("BF"));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(timeUsed)));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(index)));
    }
    else if(!algorithm.compare("BM"))
    {
        double startTime = (double)clock();
        BM(index);
        double timeUsed = (double)clock() - startTime;
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("BM"));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(timeUsed)));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(index)));
    }
    else if(!algorithm.compare("RK"))
    {
        double startTime = (double)clock();
        RK(index);
        double timeUsed = (double)clock() - startTime;
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("RK"));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(timeUsed)));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(index)));
    }
    else if(!algorithm.compare("KMP"))
    {
        double startTime = (double)clock();
        KMP(index);
        double timeUsed = (double)clock() - startTime;
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("KMP"));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(timeUsed)));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(index)));
    }

    for(int i = 0; i < 4; i++)
    {
        ui->tableWidget->item(0, i)->setFont(QFont("Times New Roman", 12));
        ui->tableWidget->item(0, i)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(0, i)->setTextAlignment(Qt::AlignCenter);
    }

    file.close();
}

void singlemode::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName();
    ui->plainTextEdit->setPlainText(filePath);
    QFileInfo fileInfo = QFileInfo(filePath);
    fileName = fileInfo.fileName();
}

bool singlemode::BF(int &index)
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

bool singlemode::RK(int &index)
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

void singlemode::generateBC(int bc[])
{

    for(int i = 0; i < plen; i++)
    {
        bc[(int)pattern[i]] = i;
    }
}

void singlemode::generateGS(int suffix[], bool prefix[])
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

int singlemode::moveByGS(int j, int suffix[], bool prefix[])
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

bool singlemode::BM(int &index)
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
            return true; //匹配成功
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

void singlemode::getNext(int *next)
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

bool singlemode::KMP(int &index)
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

void singlemode::random_string()
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

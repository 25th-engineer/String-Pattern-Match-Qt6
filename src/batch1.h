#ifndef BATCH1_H
#define BATCH1_H

#include <QWidget>
#include <QFileInfo>
#include <string>
#include <utility>
#include <QMessageBox>
#include "batch1plot.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include "mainwindow.h"
#include <QMap>

namespace Ui {
class batch1;
}

class batch1 : public QWidget
{
    Q_OBJECT

public:
    explicit batch1(QWidget *parent = nullptr);
    ~batch1();

    bool BF(int &index);
    bool RK(int &index);
    void generateBC(int []);
    void generateGS(int *, bool *);
    int moveByGS(int, int *, bool *);
    bool BM(int &index);
    void getNext(int *);
    bool KMP(int &index);
    void random_string(); // static
    static bool cmpByKeyNum(std::pair<QString, int> a, std::pair<QString, int> b)
    {
        if(a.first.length() != b.first.length())
        {
            return a.first.length() < b.first.length();
        }
        else
        {
            return a.first < b.first;
        }
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::batch1 *ui;
    // std::map<int, std::string> test_bench;
    std::string target_s;
    std::string pattern_s;
    char *target;
    char *pattern;
    int tlen;
    int plen;
    QString filePath;
    QList<QFileInfo> *fileInfo;
    std::vector< std::pair<QString,int> > timeUsedVector;
};

#endif // BATCH1_H

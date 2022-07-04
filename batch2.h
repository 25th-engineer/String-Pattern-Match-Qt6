#ifndef BATCH2_H
#define BATCH2_H

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
#include "batch2Plot.h"

namespace Ui {
class batch2;
}

class batch2 : public QWidget
{
    Q_OBJECT

public:
    explicit batch2(QWidget *parent = nullptr);
    ~batch2();

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
    void on_selectFilePushButton_clicked();

    void on_executePushButton_2_clicked();

    void on_startupPushButton_3_clicked();

private:
    Ui::batch2 *ui;

    std::string target_s;
    std::string pattern_s;
    char *target;
    char *pattern;
    int tlen;
    int plen;
    QString fileName;
    QList<QFileInfo> *fileInfo;
    std::vector< std::pair<QString,int> > timeUsedVector;
};

#endif // BATCH2_H

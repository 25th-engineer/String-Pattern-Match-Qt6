#ifndef SINGLEMODE_H
#define SINGLEMODE_H

#include <QWidget>
#include <map>
#include <string>
#include <iostream>
#include <QLineEdit>
#include <QStandardItemModel>

namespace Ui {
class singlemode;
}

class singlemode : public QWidget
{
    Q_OBJECT

public:
    explicit singlemode(QWidget *parent = nullptr);
    ~singlemode();
    bool BF(int &index);
    bool RK(int &index);
    void generateBC(int []);
    void generateGS(int *, bool *);
    int moveByGS(int, int *, bool *);
    bool BM(int &index);
    void getNext(int *);
    bool KMP(int &index);
    void random_string(); // static

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::singlemode *ui;
    std::string target_s;
    std::string pattern_s;
    char *target;
    char *pattern;
    int tlen;
    int plen;
    QString fileName;
};

#endif // SINGLEMODE_H

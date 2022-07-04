#ifndef BATCH1PLOT_H
#define BATCH1PLOT_H

#include <QMainWindow>
#include <QWidget>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QSplineSeries>
#include <QCategoryAxis>
#include <QChartView>
#include <QFileDialog>
#include <QMessageBox>
#include <cmath>
#include "mainwindow.h"

namespace Ui {
class batch1Plot;
}

class batch1Plot : public QMainWindow
{
    Q_OBJECT

public:
    explicit batch1Plot(std::vector< std::pair<QString,int> > timeUsedVector,
                        QString algorithm, QWidget *parent = nullptr);
    int getLength(int);
    ~batch1Plot();

private slots:
    void on_actionStartup_triggered();

    void on_actionExit_triggered();

    void on_actionSave_as_PNG_image_triggered();

private:
    Ui::batch1Plot *ui;
    QChartView *chartView;
    QPixmap p;
};

#endif // BATCH1PLOT_H

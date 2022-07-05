#ifndef BATCH2PLOT_H
#define BATCH2PLOT_H

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
class batch2plot;
}

class batch2plot : public QMainWindow
{
    Q_OBJECT

public:
    explicit batch2plot(std::vector< std::pair<QString,int> > timeUsedVector,
                        QString testBench, QWidget *parent = nullptr);
    ~batch2plot();

    int getLength(int);

private slots:
    void on_actionSave_as_PNG_image_triggered();

    void on_actionStartup_triggered();

    void on_actionExit_triggered();

private:
    Ui::batch2plot *ui;

    QChartView *chartView;
    QPixmap p;
};

#endif // BATCH2PLOT_H

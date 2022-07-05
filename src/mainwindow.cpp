#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "singlemode.h"
#include "batch1.h"
#include "batch2.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("String Pattern Test");
    this->setFixedSize(392, 102); // added
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Exit_triggered()
{
    this->close();
}


void MainWindow::on_About_triggered()
{
    about *a = new about();
    a->show();
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
    singlemode *singleMode = new singlemode();
    singleMode->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    batch1 *batch_1 = new batch1();
    batch_1->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
    batch2 *batch_2 = new batch2();
    batch_2->show();
}


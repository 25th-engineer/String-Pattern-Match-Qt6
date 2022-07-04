#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setFixedSize(279, 111);
    this->setWindowTitle("About");
    /*
     * // about - Copy.h about - Copy.cpp
    ui->plainTextEdit->setFixedSize(191, 91);
    ui->plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    QFont aboutFont;
    aboutFont.setPixelSize(14);
    aboutFont.setFamily("Times New Roman");
    ui->plainTextEdit->setFont(aboutFont);
    */
    ui->textBrowser->setFixedSize(261, 91);
    ui->textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
    QFont aboutFont;
    aboutFont.setPixelSize(12);
    aboutFont.setFamily("Times New Roman");
    ui->textBrowser->setFont(aboutFont);
}

about::~about()
{
    delete ui;
}

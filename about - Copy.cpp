#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setFixedSize(210, 111);
    this->setWindowTitle("About");
    ui->plainTextEdit->setFixedSize(191, 91);
    ui->plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    //ui->plainTextEdit->setWordWrapMode(QTextOption::WordWrap);

    QFont aboutFont;
    aboutFont.setPixelSize(14);
    aboutFont.setFamily("Times New Roman");
    ui->plainTextEdit->setFont(aboutFont);
}

about::~about()
{
    delete ui;
}

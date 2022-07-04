#include "batch1plot.h"
#include "ui_batch1plot.h"

batch1Plot::batch1Plot(std::vector< std::pair<QString,int> > timeUsedVector,
                       QString algorithm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::batch1Plot)
{
    ui->setupUi(this);
    this->setWindowTitle("Plot for Batch Mode 1");
    QLineSeries *series = new QLineSeries();
    // TO-DO
    int i = 0;
    int axisYRange = -1;
    for(auto viter = timeUsedVector.begin(); viter != timeUsedVector.end(); viter++)
    {
        i++;
        *series << QPointF(i, viter->second);
        axisYRange = (axisYRange > viter->second) ? axisYRange : viter->second;
    }

    series->setPointLabelsFormat("(@xPoint, @yPoint)");
    series->setPointLabelsVisible(true);
    series->setPointsVisible(true);


    QFont pointLableFont;
    pointLableFont.setPixelSize(18);
    pointLableFont.setFamily("Times New Roman");
    series->setPointLabelsFont(pointLableFont);
    series->setPointLabelsColor(Qt::red);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);


    // Customize series
    QPen pen(QRgb(0xfdb157));
    pen.setWidth(5);
    series->setPen(pen);

    // Customize chart title
    QFont titleFont;
    titleFont.setPixelSize(30);
    titleFont.setFamily("Times New Roman");
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle(QString("The Time Consumption of ") + algorithm +
                    " Algorithm Varies with The Test Bench");

    // Customize chart background
//    QLinearGradient backgroundGradient;
//    backgroundGradient.setStart(QPointF(0, 0));
//    backgroundGradient.setFinalStop(QPointF(0, 1));
//    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
//    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
//    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//    chart->setBackgroundBrush(backgroundGradient);

    // Customize plot area background
//    QLinearGradient plotAreaGradient;
//    plotAreaGradient.setStart(QPointF(0, 1));
//    plotAreaGradient.setFinalStop(QPointF(1, 0));
//    plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
//    plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
//    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//    chart->setPlotAreaBackgroundBrush(plotAreaGradient);
//    chart->setPlotAreaBackgroundVisible(true);

    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();


    // Customize axis label font
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    labelsFont.setFamily("Times New Roman");
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    QFont axisFont;
    axisFont.setPixelSize(25);
    axisFont.setFamily("Times New Roman");
    axisX->setTitleFont(axisFont);
    axisY->setTitleFont(axisFont);
    axisX->setTitleText("Test Bench Number");
    axisY->setTitleText("Time Used(ms)");

    // Customize axis colors
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(5);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::black);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axisY->setShadesVisible(true);

    int axisXRange = timeUsedVector.size();
    axisXRange += 2;
    axisX->setRange(0, axisXRange);
    axisX->setTickCount(2);
    axisX->append("", axisXRange / 2);
    axisX->append("", axisXRange);

    // TO-DO
    if(getLength(axisYRange) == 2 || getLength(axisYRange) == 1)
    {
        axisYRange += 2;
    }
    else if(getLength(axisYRange) == 3)
    {
        axisYRange += 20;
    }
    else if(getLength(axisYRange) == 4)
    {
        axisYRange += 200;
    }
    //axisYRange += 200;
    axisY->setRange(0, axisYRange);
    axisY->setTickCount(2);
    axisY->append("", axisYRange / 2);
    axisY->append("", axisYRange);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
    this->resize(800, 600);
    this->show();
}

int batch1Plot::getLength(int num)
{
    int lgth =0;
    while(num)
    {
        num /= 10;
        lgth++;
    }
    return lgth;
}

batch1Plot::~batch1Plot()
{
    delete ui;
}

void batch1Plot::on_actionStartup_triggered()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void batch1Plot::on_actionExit_triggered()
{
    this->close();
}


void batch1Plot::on_actionSave_as_PNG_image_triggered()
{
    QPixmap p = chartView->grab();
    QImage image = p.toImage();
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save as PNG Image"),"",tr("chart(*.png)"));
    if(!fileName.isNull())
    {
        image.save(fileName);
        QFileInfo file(fileName);
        if(file.exists())
        {
            QMessageBox::about(this, "Operation Successed", "The plot figure has been saved as PNG image!");
        }
        else
        {
            QMessageBox::about(this, "Operation Failed", "Failed to save as PNG image, please try again!");
        }
    }
}


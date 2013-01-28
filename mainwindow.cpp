#include "mainwindow.h"
#include "ui_mainwindow.h"
QString timeformat = "ddd dd MMMM yyyy, hh:mm";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //The timer is now thrown every 40 ms. This goes to the update slot.

}

//The paintEvent is connected to the updateslot
void MainWindow::paintEvent(QPaintEvent *){
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->labelHighest->setText("The current date and time is: " + curDateTime.toString("ddd dd MMMM yyyy, hh:mm:ss"));
    int restDays = curDateTime.daysTo(eventDateTime);
    int restHours = eventDateTime.time().hour() - curDateTime.time().hour();
    int restMin = eventDateTime.time().minute() - curDateTime.time().minute();
    if (restMin < 0){
        restHours--;
        restMin+=60;
    }
    if (restHours < 0){
        restDays--;
        restHours+=24;
    }
    QString qStrDays = QString::number(restDays), qStrHour = QString::number(restHours), qStrMinute = QString::number(restMin);
    ui->labelLower->setText("Time unit this event happens: " + qStrDays + " days, " + qStrHour + " hours and " + qStrMinute + " minutes.");
}

void MainWindow::setFileName(QString filename){
    XMLReader * xMlReader = new XMLReader(fileName);
    bool ok = true;
    xMlReader->readFile(ok);
    eventName = "landing op schiphol. Eindelijk thuis =) (bijna dan)";
    QDate date(2013,2,2);
    QTime time(15,50,0,0);
    eventDateTime = QDateTime(date,time);
    ui->labelUpper->setText("Counting down to: " + eventName);
    ui->labelMiddle->setText("This event takes place on: "+ eventDateTime.toString("ddd dd MMMM yyyy, hh:mm"));
    setTimer(true);
}

void MainWindow::setTimer(bool start){
    if (start){
        timer->start(1000);
    } else{
        timer->stop();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

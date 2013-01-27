#include "mainwindow.h"
#include "ui_mainwindow.h"
QString timeformat = "ddd dd MMMM yyyy, hh:mm";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eventName = "landing op schiphol. Eindelijk thuis =) (bijna dan)";
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //The timer is now thrown every 40 ms. This goes to the update slot.
    timer->start(1000);
    QDate date(2013,2,2);
    QTime time(15,50,0,0);
    eventDateTime = QDateTime(date,time);
    ui->labelUpper->setText("Counting down to: " + eventName);
    ui->labelMiddle->setText("This event takes place on: "+ endDateTime.toString("ddd dd MMMM yyyy, hh:mm"));    
}

//The paintEvent is connected to the updateslot
void MainWindow::paintEvent(QPaintEvent *){
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->labelHighest->setText("The current date and time is: " + curDateTime.toString("ddd dd MMMM yyyy, hh:mm:ss"));
    int restDays = curDateTime.daysTo(endDateTime);
    int restHours = endDateTime.time().hour() - curDateTime.time().hour();
    int restMin = endDateTime.time().minute() - curDateTime.time().minute();
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

MainWindow::~MainWindow()
{
    delete ui;
}

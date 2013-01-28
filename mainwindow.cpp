#include "mainwindow.h"
#include "ui_mainwindow.h"
QString timeformat = "ddd dd MMMM yyyy, hh:mm";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->labelHighest->setText("The current date and time is: " + curDateTime.toString("ddd dd MMMM yyyy, hh:mm:ss"));
    ui->labelUpper->clear();
    ui->labelMiddle->clear();
    ui->labelLower->clear();
    connect(timer, SIGNAL(timeout()), this, SLOT(currentTimerSlot()));
    timer->start(1000);
}

//The paintEvent is connected to the updateslot
void MainWindow::eventTimerSlot(){
    QDateTime curDateTime = QDateTime::currentDateTime();
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

void MainWindow::currentTimerSlot(){
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->labelHighest->setText("The current date and time is: " + curDateTime.toString("ddd dd MMMM yyyy, hh:mm:ss"));
}



void MainWindow::setFileName(QString fileName){
    XMLReader * xMlReader = new XMLReader(fileName);
    bool ok = true;
    eventList = xMlReader->readFile(&ok);
    if (!ok){
        eventName.clear();
        ui->labelUpper->setText("<font color='red'>Error opening file " + fileName + "</font>" );
        ui->labelMiddle->setText("<font color='red'>Check if the file exists and if the program has read acces</font>");
        return;
    }

    QSignalMapper * signalMapper = new QSignalMapper(this);
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(setEventSlot(int)));
    for (int i = 0; i < eventList.length();i++){
        actions.append(ui->menuEvents->addAction(eventList.at(i)->getName()));
        actions.at(i)->setCheckable(true);
        signalMapper->setMapping(actions.at(i),i);
        connect(actions.at(i),SIGNAL(triggered()),signalMapper,SLOT(map()));
    }

    eventDescription = "landing op schiphol. Eindelijk thuis =) (bijna dan)";
    QDate date(2013,2,2);
    QTime time(15,50,0,0);
    eventDateTime = QDateTime(date,time);
    ui->labelUpper->setText("Counting down to: " + eventDescription);
    ui->labelMiddle->setText("This event takes place on: "+ eventDateTime.toString("ddd dd MMMM yyyy, hh:mm"));
    eventTimerSlot();
    connect(timer,SIGNAL(timeout()),this,SLOT(eventTimerSlot()));

}

void MainWindow::setEventSlot(int event){
#ifdef QT_DEBUG
    qDebug() << "MainWindow::setEventSlot(int event) says: event no: " + QString::number(event);
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}

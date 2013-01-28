#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stable.h"

#include <QMainWindow>
#include <iostream>
#include <time.h>
#include <XMLClass.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setFileName(QString filename);
private:
    //methods
    void setTimer(bool start);
    //variables
    Ui::MainWindow *ui;
    QTimer *timer;

    QString fileName;

    QList<EventObject> eventList;

    QDateTime eventDateTime;
    QString eventName;
    QString eventDescription;
    qint64 epochEventTime;
    //methods/functions
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H

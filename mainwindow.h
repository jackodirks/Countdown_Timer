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
    void setFileName(QString fileName);
private:
    //variables
    Ui::MainWindow *ui;
    QTimer *timer;

    QList<EventObject*> eventList;
    QList<QAction*> actions;

    QDateTime eventDateTime;
    QString eventName;
    QString eventDescription;
    qint64 epochEventTime;

private slots:
    void currentTimerSlot();
    void eventTimerSlot();
    void setEventSlot(int event);
};

#endif // MAINWINDOW_H

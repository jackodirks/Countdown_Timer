#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stable.h"

#include <QMainWindow>
#include <iostream>
#include <time.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
     void timer();
    
private:
    //variables
    Ui::MainWindow *ui;
    QDateTime endDateTime;
    QString eventName;
    qint64 epochEventTime;
    //methods/functions
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H

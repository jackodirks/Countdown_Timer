#include "stable.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef QT_DEBUG
    for (int i = 0; i < a.arguments().length(); i++){
        qDebug()<<"Argument" << QString::number(i) << a.arguments().at(i);
    }
#endif
    QString fileName = "event.xml";
    for (int i = 0; i < a.arguments().length(); i++){
        if (a.arguments().at(i) == "-s"){
            if ( (a.arguments().length() > i+1)){
                fileName = a.arguments().at(i+1);
            } else {
                qCritical("Error: expected path, got nothing. (Usage: -s <PATH>");
                return 1;
            }
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}

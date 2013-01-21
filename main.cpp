#include "stable.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout<<"Test";
#ifdef QT_DEBUG;
    for (int i = 0; i < a.arguments().length(); i++){
        qDebug()<<"Argument" << QString::number(i) << a.arguments().at(i) << endl;
    }
#endif
    MainWindow w;
    w.show();
    return a.exec();
}

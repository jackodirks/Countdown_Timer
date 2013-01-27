#ifndef XMLCLASS_H
#define XMLCLASS_H

#endif // XMLCLASS_H

#include "stable.h"

class EventObject{
public:
    //constructor
    EventObject(qint64 epochTime, QString name, QString message);
    //getters
    qint64 getEpochTime();
    QString getName();
    QString getMessage();
private:
    quint64 epochTime;
    QString name;
    QString message;
};

class XMLReader{
public:
    //methods
    XMLReader(QString fileName);
    QList<EventObject> readFile(bool *ok);
private:
    //methods
    //variables
    QString fileName;
};

#ifndef XMLCLASS_H
#define XMLCLASS_H


#include "stable.h"

class EventObject{
public:
    //constructor
    EventObject(QString name, QString description, uint epochTime);
    ~EventObject();
    //getters
    uint getEpochTime();
    QString getName();
    QString getDescription();
private:
    uint epochTime;
    QString name;
    QString description;
};

class XMLReader{
public:
    //methods
    XMLReader(QString fileName);
    ~XMLReader();
    QList<EventObject*> readFile(bool * ok);
private:
    //methods
    //variables
    QString fileName;
};

#endif // XMLCLASS_H

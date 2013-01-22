#include "XMLClass.h"
#include <QXmlStreamReader>

//class XMLReader
XMLReader::XMLReader(QString fileName){
    this->fileName = fileName;
}

bool XMLReader::readFile(QList<EventObject> *&eventObjectList){
    //combotje van:
    //http://stackoverflow.com/questions/3092387/c-qt-read-xml-file
    //http://stackoverflow.com/questions/2947819/reading-root-element-in-xml-not-the-child/2948807#2948807
    return false;
}

//class eventObject
EventObject::EventObject(qint64 epochTime, QString name, QString message){
    this->epochTime = epochTime;
    this->message = message;
    this->name = name;
}

qint64 EventObject::getEpochTime(){
    return epochTime;
}

QString EventObject::getMessage(){
    return message;
}

QString EventObject::getName(){
    return name;
}


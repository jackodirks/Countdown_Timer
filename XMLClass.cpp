#include "XMLClass.h"
#include <QXmlStreamReader>

//class XMLReader
XMLReader::XMLReader(QString fileName){
    this->fileName = fileName;
}

QList<EventObject> XMLReader::readFile(bool * ok){
    QList<EventObject> list;
    QFile * xmlFile = new QFile(fileName);
    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
#ifdef QT_DEBUG
        qDebug() << "Load XML File Problem" << "Couldn't open" << fileName;
#endif
        ok = false;
        return list;
    }
    QXmlStreamReader * xmlReader = new QXmlStreamReader(xmlFile);

    while (!xmlReader->atEnd() && !xmlReader->hasError()){
            QXmlStreamReader::TokenType token = xmlReader->readNext();
            if(token == QXmlStreamReader::StartDocument) {
                continue;
            }
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {

            if (xmlReader->name() == "name") {
                continue;
            }

            if(xmlReader->name() == "id") {
#ifdef QT_DEBUG
                qDebug() << xmlReader->readElementText();
#endif
            }
        }
    }

    //combotje van:
    //http://stackoverflow.com/questions/30false92387/c-qt-read-xml-file
    //http://stackoverflow.com/questions/2947819/reading-root-element-in-xml-not-the-child/2948807#2948807
    return list;
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


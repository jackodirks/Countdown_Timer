#include "XMLClass.h"
#include <QXmlStreamReader>

//class XMLReader
XMLReader::XMLReader(QString fileName){
    this->fileName = fileName;
}

QList<EventObject *> XMLReader::readFile(bool *ok){
    QList<EventObject *> list;
    QFile * xmlFile = new QFile(fileName);
    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
#ifdef QT_DEBUG
        qDebug() << "Load XML File Problem" << "Couldn't open" << fileName;
#endif
        *ok = false;
        return list;
    }
    QXmlStreamReader * xmlReader = new QXmlStreamReader(xmlFile);
    QString name, description, epochtime;
    while (!xmlReader->atEnd() && !xmlReader->hasError()){
            QXmlStreamReader::TokenType token = xmlReader->readNext();
            if(token == QXmlStreamReader::StartDocument) {
                continue;
            }
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {

            if (xmlReader->name() == "event") {
#ifdef QT_DEBUG
                qDebug() << xmlReader->attributes().at(0).value();
#endif
                name = xmlReader->attributes().at(0).value().toString();
                description.clear();
                epochtime.clear();
                continue;
            }

            if(xmlReader->name() == "description") {
                description = xmlReader->readElementText();
#ifdef QT_DEBUG
                qDebug() << description;
#endif

                continue;
            }

            if (xmlReader->name() == "epochtime"){
                epochtime=xmlReader->readElementText();
#ifdef QT_DEBUG
                qDebug() << epochtime;

#endif

                bool ok = false;
                uint epochtimeUint = epochtime.toUInt(&ok);
                if (name.length() > 0 && description.length() > 0 && ok){
                    list.append(new EventObject(name, description,epochtimeUint));
                }
            }
        }
    }
#ifdef QT_DEBUG
    if (xmlReader->hasError()){
        qDebug() << "Error in XMLReader";
        qDebug() << xmlReader->errorString();
    }
#endif
    xmlFile->close();
    xmlReader->clear();

    //combotje van:
    //http://stackoverflow.com/questions/30false92387/c-qt-read-xml-file
    //http://stackoverflow.com/questions/2947819/reading-root-element-in-xml-not-the-child/2948807#2948807
    return list;
}

//class eventObject
EventObject::EventObject(QString name, QString description, uint epochTime){
    this->epochTime = epochTime;
    this->description = description;
    this->name = name;
}

uint EventObject::getEpochTime(){
    return epochTime;
}

QString EventObject::getDescription(){
    return description;
}

QString EventObject::getName(){
    return name;
}


#include "databasehandler.h"

#include <QNetworkRequest>
#include <QDebug>
#include <QVariantMap> //1
//3
#include <QJsonDocument>

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject{parent}
{
    m_networkManager = new QNetworkAccessManager(this);
    //2
    QVariantMap newPet;
    newPet["Type"] = "Dog";
    newPet["Food"] = "Chicken";
    newPet["Name"] = "Mercy";

    //4 Create new json file
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newPet);
    //5 Create new network request called newPetrequest

    QNetworkRequest newPetrequest(QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets.json"));

    //6 Set a header
    newPetrequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    //7 Perform a POST Request
    m_networkManager->post(newPetrequest,jsonDoc.toJson());

    //Run

//nagana?
}

DatabaseHandler::~DatabaseHandler()
{
    m_networkManager -> deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
    qDebug()<<m_networkReply->readAll();
}


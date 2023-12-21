#include "server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::handleNewTcpConnection);
}

Server::~Server()
{
}

void Server::start(int port)
{
    // TODO: Get the port number from the input
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started. Listening...";
    }
}

void Server::stop()
{

}

void Server::handleNewTcpConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();

    connect(clientSocket, &QTcpSocket::readyRead, this, [=]() {
        handleTcpData(clientSocket);
    });

    qDebug() << "New client connected..." ;
}

void Server::handleTcpData(QTcpSocket *socket)
{
    if (socket->bytesAvailable() > 0) {
        QByteArray requestData = socket->readAll();
        QString jsonString(requestData);

        // Parse the JSON data
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            qDebug() << "JSON parse error:" << parseError.errorString();
            return;
        }

        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();

            // Extract data from JSON object
            QString clientName = jsonObj["clientName"].toString();
            QString clientIp = jsonObj["clientIp"].toString();
            int clientId = clients.size();

            ClientData clientData(clientName, QHostAddress(clientIp), clientId);
            clients.insert(clientId, clientData);

            qDebug() << "New client login " << clientId << ", with nickname " << clientName;

            // Prepare and send the response JSON
            QJsonObject responseObj;
            responseObj["id"] = clientId; // Assuming you want to send the client ID as response

            QJsonDocument responseDoc(responseObj);
            QByteArray responseData = responseDoc.toJson(QJsonDocument::Compact);

            socket->write(responseData); // Sending the response back to the client

        }
    }
}

QString Server::getLocalIpAddress()
{
    QString localIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // Retrieve the first non-localhost IPv4 address
    for (const QHostAddress &address : ipAddressesList) {
        if (address != QHostAddress::LocalHost && address.toIPv4Address()) {
            localIpAddress = address.toString();
            break;
        }
    }
    return localIpAddress;
}

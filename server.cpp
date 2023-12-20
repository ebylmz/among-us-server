#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
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
        emit serverStarted();
    }
}

void Server::stop()
{

}

void Server::newConnection()
{
    qDebug() << "New client connected...";

    while (tcpServer->hasPendingConnections()) {
        QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
        clients.append(clientSocket);
        connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readClientData);
    }
}

void Server::readClientData()
{
    for (QTcpSocket *client : clients) {
        if (client->bytesAvailable() > 0) {
            // Read data from the client
            QByteArray data = client->readAll();
            qDebug() << "Received data: " << data;

            // Check if it is registered player, looking the hash map
            // read the packet accordingly for this information
/*
            if (false) {
                PlayerInfo *player = new PlayerInfo("player 1", false, Red);
                emit newPlayer(player);
            }
            else {
                // Update the game map based on received information
                PlayerTransform *ptransform = new PlayerTransform(300, 300, true);
                emit updatePlayer(ptransform);
            }
*/

            // Processing received data
            QString receivedData = QString::fromUtf8(data);
            qDebug() << "Received from client:" << receivedData;
            qDebug() << "Received from client:" << data;
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

#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);

    QString localIpAddress = getLocalIpAddress();
    ui->ipAddressLabel->setText("IP Address: " + localIpAddress);

    tcpServer = new QTcpServer(this);
    connect(ui->runButton, &QPushButton::clicked, this, &Server::startServer);
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
}

Server::~Server()
{
    delete ui;
}

void Server::startServer()
{
    // QString serverIP = ui->ipAdressLabel->text();
    int port = ui->portLineEdit->text().toInt();

    // TODO: Get the port number from the input
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started. Listening...";
        emit serverStarted();
    }
}

void Server::newConnection() {
    while (tcpServer->hasPendingConnections()) {
        QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
        clients.append(clientSocket);
        connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readClientData);
    }
}

void Server::readClientData() {
    for (QTcpSocket *client : qAsConst(clients)) {
        if (client->bytesAvailable() > 0) {
            // Read data from the client
            QByteArray data = client->readAll();

            // Process the data (e.g., extract player information)
            // Update the game map based on received information

            // Example: Processing received data
            QString receivedData = QString::fromUtf8(data);
            qDebug() << "Received from client:" << receivedData;
        }
    }
}

QString Server::getLocalIpAddress() {
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

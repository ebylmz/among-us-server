#include "serverConnection.h"
#include "gameStatusPage.h"

ServerConnection::ServerConnection(QWidget *parent) : QWidget(parent) {
    ipLineEdit = new QLineEdit;
    portLineEdit = new QLineEdit;
    connectButton = new QPushButton("Connect");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Server IP:"));
    layout->addWidget(ipLineEdit);
    layout->addWidget(new QLabel("Port:"));
    layout->addWidget(portLineEdit);
    layout->addWidget(connectButton);

    socket = new QTcpSocket(this);

    connect(connectButton, &QPushButton::clicked, this, &ServerConnection::connectToServer);
}

void ServerConnection::connectToServer() {
    QString serverIP = ipLineEdit->text();
    int port = portLineEdit->text().toInt();

    // Logic to connect to the game server using socket
    socket->connectToHost(serverIP, port);

    if (true or socket->waitForConnected()) {
        emit connectionEstablished(); // Emit signal on successful connection
        // Other code remains unchanged
    } else {
        // Connection failed, handle error
        QMessageBox::critical(this, "Connection Error", "Unable to connect to the server!");
    }
}


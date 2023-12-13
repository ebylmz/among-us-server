#include "serverConfiguration.h"
#include "ui_serverConfiguration.h"

ServerConfiguration::ServerConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerConfiguration)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
}

ServerConfiguration::~ServerConfiguration()
{
    delete ui;
}

void ServerConfiguration::on_createButton_clicked()
{
    QString serverIP = ui->ipLineEdit->text();
    int port = ui->portLineEdit->text().toInt();

    // Logic to connect to the game server using socket
    //socket->connectToHost(serverIP, port);

    if (true || socket->waitForConnected()) {
        emit connectionEstablished(); // Emit signal on successful connection
        // Other code remains unchanged
    } else {
        // Connection failed, handle error
        QMessageBox::critical(this, "Connection Error", "Unable to connect to the server!");
    }
}

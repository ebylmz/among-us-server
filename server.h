#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QNetworkInterface>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void startServer();
    void newConnection();
    void readClientData();

signals:
    void serverStarted();

private:
    Ui::Server *ui;
    QTcpServer *tcpServer;
    QList<QTcpSocket *> clients;

    QString getLocalIpAddress();
};

#endif // SERVER_H

#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QJsonParseError>
#include <QJsonObject>
#include <utils.h>

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
    QString getLocalIpAddress();
    void start(int port);
    void stop();

private slots:
    void handleNewTcpConnection();
    void handleTcpData(QTcpSocket *socket);
/*
signals:
    void updatePlayer(PlayerTransform *ptransform);
*/

private:
    QTcpServer *tcpServer;
    QMap<int, ClientData> clients;
};

#endif // SERVER_H

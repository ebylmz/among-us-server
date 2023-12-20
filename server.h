#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QNetworkInterface>
#include <player.h>


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
    void newConnection();
    void readClientData();

signals:
    void serverStarted();
    void newPlayer(PlayerInfo *player);
    void updatePlayer(PlayerTransform *ptransform);

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket *> clients;
};

#endif // SERVER_H

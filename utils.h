#ifndef UTILS_H
#define UTILS_H

#include <QWidget>
#include <QNetworkInterface>

class PlayerTransform
{
public:
    PlayerTransform(int x, int y, bool isLive);
    ~PlayerTransform();

private:
    int x;
    int y;
    bool isLive;
};

class ClientData
{
public:
    ClientData(QString name, QHostAddress ip, int id);
    ClientData();
    ~ClientData();

    QString getName();
    void setName(QString name);

    int getPacketCounter();
    void setPacketCounter(int counter);

    PlayerTransform getPlayerTransform();
    void setPlayerTransform(PlayerTransform transform);

private:
    QString name;
    QHostAddress ip;
    int id;
    PlayerTransform playerTransform;
    int packetCounter;
};

struct LoginRequest
{
    QString clientName;
    QString clientIp;

    LoginRequest(const QString& name) : clientName(name), clientIp("123") {}
};
#endif // UTILS_H

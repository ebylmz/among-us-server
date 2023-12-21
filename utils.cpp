#include "utils.h"

PlayerTransform::PlayerTransform(int x, int y, bool isLive) :
    x(x), y(y), isLive(isLive)
{
}

PlayerTransform::~PlayerTransform()
{
}


ClientData::ClientData(QString name, QHostAddress ip, int id)
    : name(name), ip(ip), id(id), playerTransform(0, 0, true)
{}

ClientData::~ClientData()
{}

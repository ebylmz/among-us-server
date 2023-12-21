#include "utils.h"

PlayerTransform::PlayerTransform(int x, int y, bool isLive) :
    x(x), y(y), isLive(isLive)
{
}

PlayerTransform::~PlayerTransform()
{
}

int PlayerTransform::getX() { return x; }

void PlayerTransform::setX(int x) { this->x = x; }

int PlayerTransform::getY() { return y; }

void PlayerTransform::setY(int y) {this->y = y; }

ClientData::ClientData(QString name, QHostAddress ip, int id)
    : name(name), ip(ip), id(id), playerTransform(0, 0, true), packetCounter(0)
{}

ClientData::ClientData()
    : name("username"), ip("0.0.0.0"), id(0), playerTransform(0, 0, true), packetCounter(0)
{}

ClientData::~ClientData() {}

QString ClientData::getName() { return name; }

void ClientData::setName(QString name) { this->name = name; }

int ClientData::getPacketCounter() { return packetCounter; }

void ClientData::setPacketCounter(int counter) { packetCounter = counter; }

QHostAddress ClientData::getIpAddress() { return ip; }

void ClientData::setIpAddress(QHostAddress ip) { this->ip = ip;}

PlayerTransform ClientData::getPlayerTransform() { return playerTransform; }

void ClientData::setPlayerTransform(PlayerTransform transform) { playerTransform = transform; }

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

enum Color
{
    Red, White, Green, Blue, Purple, Yellow
};

class PlayerInfo
{
public:
    PlayerInfo(std::string pname, bool isImposter, Color skinColor);
    ~PlayerInfo();

private:
    std::string pname;
    bool isImposter;
    Color skinColor;
};

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

#endif // PLAYER_H

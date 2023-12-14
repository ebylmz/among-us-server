#include "player.h"

PlayerInfo::PlayerInfo(std::string pname, bool isImposter, Color skinColor) :
    pname(pname), isImposter(isImposter), skinColor(skinColor)
{
}

PlayerInfo::~PlayerInfo()
{
}

PlayerTransform::PlayerTransform(int x, int y, bool isLive) :
x(x), y(y), isLive(isLive)
{
}

PlayerTransform::~PlayerTransform()
{
}

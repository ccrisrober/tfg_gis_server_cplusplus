#include "ObjectUser.h"


ObjectUser::ObjectUser(int id, float posX, float posY, int map, int rollDice)
	: id(id), posX(posX), posY(posY), map(map), rollDice(rollDice)
{
}


ObjectUser::~ObjectUser()
{
}

int ObjectUser::getId() { return id; }
float ObjectUser::getPosX() { return posX; }
float ObjectUser::getPosY() { return posY; }
int ObjectUser::getMap() { return map; }
int ObjectUser::getRollDice() { return rollDice; }
void ObjectUser::setPosition(float x, float y) {
	posX = x; posY = y;
}

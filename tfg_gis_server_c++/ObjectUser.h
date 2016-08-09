#pragma once
class ObjectUser
{
public:
	ObjectUser(int id, float posX, float posY, int map = 0, int rollDice = 0);
	~ObjectUser();

	int getId();
	float getPosX();
	float getPosY();
	int getMap();
	int getRollDice();
	void setPosition(float x, float y);

protected:
	int id;
	float posX;
	float posY;
	int map;
	int rollDice;

};

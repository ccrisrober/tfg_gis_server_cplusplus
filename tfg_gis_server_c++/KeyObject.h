#pragma once
#include <string>
class KeyObject
{
public:
	KeyObject(int id, float posX, float posY, std::string color);
	~KeyObject();

	int getId() {
		return id;
	}
	float getPosX() {
		return posX;
	}
	float getPosY() {
		return posY;
	}
	std::string getColor() {
		return color;
	}
	void setPosition(float x, float y) {
		this->posX = x;
		this->posY = y;
	}

private:
	int id;
	float posX;
	float posY;
	std::string color;
};


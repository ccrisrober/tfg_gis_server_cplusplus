#pragma once
#include "KeyObject.h"
#include "RealObjects.h"
#include <vector>
#include <map>
class Map
{
public:
	Map(int id, std::string fields, int width, int height, std::map<std::string, KeyObject*> objects);
	~Map();

	int getId() {
		return id;
	}
	std::string getMapFields() {
		return mapFields;
	}
	int getWith() {
		return width;
	}
	int getHeight() {
		return height;
	}
	std::vector<KeyObject*> getKeyObjects() {
		std::vector<KeyObject*> vints;
		for (auto imap : objects)
			vints.push_back(imap.second);
		return vints;
	}
	KeyObject* removeKey(int idx) {
		return objects[std::to_string(idx)];
	}
	bool addKey(int idx, float px, float py) {
		auto ko = RealObjects::Instance()->getKey(idx);
		ko->setPosition(px, py);
		if (ko != nullptr) {
			objects[std::to_string(idx)] = ko;
			return true;
		}
		return false;
	}

protected:
	int id;
	std::string mapFields;
	int width;
	int height;
protected:
	std::map<std::string, KeyObject*> objects;
};


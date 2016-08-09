#pragma once

#include <unordered_map>
#include "KeyObject.h"

class RealObjects
{
public:
	static RealObjects * Instance();
	KeyObject* getKey(int id) {
		return objects[id];
	}
	void addKey(int id, KeyObject *ko) {
		objects[id] = ko;
	}

protected:
	RealObjects();
	~RealObjects();
private:
	static RealObjects * pInstance;
	std::unordered_map<int, KeyObject*> objects;
};


#include "RealObjects.h"

RealObjects* RealObjects::pInstance = 0;
RealObjects * RealObjects::Instance() {
	if (pInstance == 0) {
		pInstance = new RealObjects;
	}
	return pInstance;
}
RealObjects::RealObjects()
{
}

RealObjects::~RealObjects()
{
	for (std::unordered_map<int, KeyObject*>::iterator it = this->objects.begin();
		it != this->objects.end();) {
		delete (*it).second;
		objects.erase(it++);
	}
}

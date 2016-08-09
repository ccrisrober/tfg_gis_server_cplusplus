#include "Map.h"


Map::Map(int id, std::string fields, int width, int height, std::map<std::string, KeyObject*> objects)
	: id(id), mapFields(fields), width(width), height(height), objects(objects)
{
}


Map::~Map()
{
}

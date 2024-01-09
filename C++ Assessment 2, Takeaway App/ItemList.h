#pragma once
#include "Item.h"
#include <vector>
class ItemList //Abstract class
{
public:

	virtual std::string toString() = 0; //pure virtual function

	std::vector<Item*> items; //pointer vector


private:
	
};


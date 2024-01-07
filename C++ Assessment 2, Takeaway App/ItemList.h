#pragma once
#include "Item.h"
#include <vector>
class ItemList //Abstract class
{
public:
	std::vector<Item*> items;

	virtual void toString() = 0; //pure virtual function
};


#pragma once
#include "Item.h"
class Beverage: public Item
{
private:
	float abv;
	int volume;

	bool isAlcoholic();
	int toString();
};


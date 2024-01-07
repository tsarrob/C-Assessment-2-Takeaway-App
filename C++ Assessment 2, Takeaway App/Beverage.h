#pragma once
#include "Item.h"
class Beverage: public Item
{
private:
	//private attributers
	float abv;
	int volume;

	//get functions
	float getAbv();
	int getVolume();

	//other functions
	bool isAlcoholic();
	std::string toString();
};


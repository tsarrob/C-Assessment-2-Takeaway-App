#pragma once
#include "Item.h"
class Beverage: public Item
{
public:
	//constructor
	Beverage(std::string name, double price, int calories, float abv, int volume);

	std::string toString();

private:
	//private attributers
	float abv;
	int volume;

	//get functions
	float getAbv();
	int getVolume();

	//other functions
	bool isAlcoholic();
	
};


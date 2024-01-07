#pragma once
#include "Item.h"
class Beverage: public Item
{
public:
	//constructor
	Beverage(std::string name, double price, int calories, double abv, int volume);

	std::string toString();

private:
	//private attributers
	double abv;
	int volume;

	//get functions
	double getAbv();
	int getVolume();

	//other functions
	bool isAlcoholic();
	
};


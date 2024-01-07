#include "Item.h"


Item::Item(std::string name, double price, int calories) //constructor, giving item attributes that are passed through when initialising
	:
	name(name), price(price), calories(calories) {}


Item::~Item() //deconstructor
{

}


//get functions
int Item::getCalories()
{
	return calories;
}

std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

//other functions
std::string Item::toString()
{
	return;
}

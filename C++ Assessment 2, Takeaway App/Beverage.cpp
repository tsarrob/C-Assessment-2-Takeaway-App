#include "Beverage.h"

//constructor
Beverage::Beverage(std::string name, double price, int calories, float abv, int volume)
	:Item(name, price, calories), abv(abv), volume(volume) {}


//get functions
float Beverage::getAbv()
{
	return abv;
}
int Beverage::getVolume()
{
	return volume;
}



//other functions
bool Beverage::isAlcoholic()
{
	return 0;
}

std::string Beverage::toString()
{
	return "return";
}
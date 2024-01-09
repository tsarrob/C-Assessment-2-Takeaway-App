#include "Beverage.h"

//constructor
Beverage::Beverage(std::string name, double price, int calories, double abv, int volume)
	:Item(name, price, calories), abv(abv), volume(volume) {}


//get functions
double Beverage::getAbv()
{
	return abv;
}
int Beverage::getVolume()
{
	return volume;
}
char Beverage::getType()
{
	return 'b';
}


//other functions
bool Beverage::isAlcoholic()
{
	return 0;
}

std::string Beverage::toString()
{
    std::stringstream result;

    result << Item::getName() << ": $" << Item::getPrice() << ", " << Item::getCalories() << " calories, ";

	if (getAbv() > 0)
	{
		result << "Abv:" << getAbv() << "%, ";
	}

	result << getVolume() << " ml";

    return result.str();
}
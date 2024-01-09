#include "Appetiser.h"


//constructor
Appetiser::Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne)
	:Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

//get functions
bool Appetiser::getShareable()
{
	return shareable;
}
bool Appetiser::getTwoForOne()
{
	return twoForOne;
}
char Appetiser::getType()
{
	return 'a';
}



//other functions
std::string Appetiser::toString()
{
    std::stringstream result;

    result << Item::getName() << ": $" << Item::getPrice() << ", " << Item::getCalories() << " calories, ";

    if (getShareable())
    {
        result << " [shareable]";
    }
    if (getTwoForOne())
    {
        result << " [twoForOne]";
    }

    return result.str();
}
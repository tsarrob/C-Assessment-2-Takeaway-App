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


//other functions
std::string Appetiser::toString()
{
	return;
}
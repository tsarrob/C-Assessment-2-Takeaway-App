#pragma once
#include "Item.h"
class Appetiser: public Item 
{

public:

	//constructor 
	Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne);

	//other functions
	std::string toString();
	bool getTwoForOne();

private:

	//private attributes
	bool shareable;
	bool twoForOne;

	//get functions
	bool getShareable();
	
	char getType();
	
	
};


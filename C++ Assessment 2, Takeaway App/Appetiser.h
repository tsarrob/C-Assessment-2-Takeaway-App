#pragma once
#include "Item.h"
class Appetiser: public Item 
{
private:

	//private attributes
	bool shareable;
	bool twoForOne;

	//get functions
	bool getShareable();
	bool getTwoForOne();
	


public:
	//other functions
	std::string toString();
};


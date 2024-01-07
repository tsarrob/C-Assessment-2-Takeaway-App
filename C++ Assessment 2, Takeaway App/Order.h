#pragma once
#include "ItemList.h"
#include <string>

class Order: public ItemList
{
public:
	std::string toString() override;

private:
	//private attributes
	double total;

	//private functions
	double calculateTotal();
	std::string printReceipt();
	
	
};


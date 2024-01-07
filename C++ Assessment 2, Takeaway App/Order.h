#pragma once
#include "ItemList.h"
#include <string>

class Order: public ItemList
{
private:
	float total;

	float calculateTotal();
	std::string printReceipt();
	int toString();
};


#pragma once
#include "Item.h"
#include "Menu.h"
#include <string>

class Order: public ItemList
{
public:
	Order(); //constructor
	~Order(); //desctructor


	//other functions
	std::string toString() override;

	void addOrder(Item* item);
	void removeOrder(int index);

private:

	std::vector<Item*> orderItems; //pointer vector

	//private attributes
	double total;

	//private functions
	double calculateTotal();
	std::string printReceipt();
	
	
};


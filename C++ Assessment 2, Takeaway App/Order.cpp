#include "Order.h"


//constructor
Order::Order() 
	: orderItems(), total(0.00) {
} //empty vector


//destructor
Order::~Order() {} 



//other functions
double Order::calculateTotal()
{
	return 0;
}

std::string Order::printReceipt()
{
	return "return";
}

std::string Order::toString()
{
	return "return";
}

void Order::addOrder(int index)
{
		std::cout << "erorr here";
		orderItems.push_back(items[index]);

}
void Order::removeOrder(int index)
{
	if (index >= 0 && index < orderItems.size()) {
		orderItems.erase(orderItems.begin() + index);
	}
	else {
		std::cout << "Input out of range, please make sure you only try removing what has already been ordered" << std::endl;
		//out of bounds
	}
}

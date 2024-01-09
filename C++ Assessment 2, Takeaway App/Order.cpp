#include "Order.h"
#include "Appetiser.h"


//constructor
Order::Order() 
	: orderItems(), total(0.00) {
} //empty vector


//destructor
Order::~Order() {} 



//other functions
double Order::calculateTotal()
{
	double total = 0.0;
	double totalDiscount = 0.0;
	int TwoForOne = 0;

	for (const auto& item : orderItems)
	{
		total += item->getPrice();

		if (item->getType() == 'a')
		{
			//if (dynamic_cast<Appetiser*>(item)->getTwoForOne()) //converts base class back to derived class since i held it in base container
			//{
			//	TwoForOne += 1;

			//}
		}
		
	}
	return total;

}

std::string Order::printReceipt()
{
	return "return";
}

std::string Order::toString()
{
	std::ostringstream orderString;

	orderString << "\n------------ Your Order ------------" << std::endl;


	for (int i = 0; i < orderItems.size(); ++i)
	{
		orderString << i + 1 << ". " << orderItems[i]->toString() << std::endl;
	}

	orderString << "Order Total: $" << Order::calculateTotal() << std::endl <<std::endl;
	return orderString.str();
}

void Order::addOrder(Item* item)
{
		orderItems.push_back(item);
}
void Order::removeOrder(int index)
{
	if (index >= 1 && index < orderItems.size()) {
		orderItems.erase(orderItems.begin() + index - 1);
	}
	else {
		std::cout << "Input out of range, please make sure you only try removing what has already been ordered" << std::endl;
		//out of bounds
	}
}

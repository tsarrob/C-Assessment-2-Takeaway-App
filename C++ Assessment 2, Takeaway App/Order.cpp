#include "Order.h"
#include "Appetiser.h"
#include "algorithm"


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
	int TwoForOneValid = 0;
	std::vector <double> discounts;
	for (const auto& item : orderItems)
	{
		
		total += item->getPrice();

		if (item->getType() == 'a')
		{
			if (dynamic_cast<Appetiser*>(item)->getTwoForOne()) //converts base class back to derived class since i held it in base container
			{
				discounts.push_back(item->getPrice());
				TwoForOne += 1;

				if (TwoForOne % 2 == 0)
				{
					TwoForOneValid += 1;

				}
				
			}
		}
		
	}
	if (TwoForOneValid > 0)
	{
		std::sort(discounts.begin(), discounts.end(), std::greater<double>());
		for (int i = 0; i < TwoForOneValid; i++)
		{
			totalDiscount += discounts.back();
			discounts.pop_back();
		}
		discount = totalDiscount;

	}
	
	return total - totalDiscount;

}



std::string Order::printReceipt()
{
	return "return";
}

std::string Order::toString()
{
	double Total = calculateTotal();
	std::ostringstream orderString;


	orderString << "\n------------ Your Order ------------" << std::endl;


	for (int i = 0; i < orderItems.size(); ++i)
	{
		orderString << i + 1 << ". " << orderItems[i]->toString() << std::endl;
	}
	if (discount != 0)
	{
		orderString << "\n2-4-1 Discount applied! Savings: $" << discount << std::endl;
	}
	orderString << "Order Total: $" << Total << std::endl <<std::endl;
	return orderString.str();
}

void Order::addOrder(Item* item)
{
		orderItems.push_back(item);
}
void Order::removeOrder(int index)
{
	if (index >= 1 && index <= orderItems.size()) {
		std::cout << orderItems[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1]->getName() << " has been removed!" << std::endl;
		orderItems.erase(orderItems.begin() + index - 1);
	}
	else {
		std::cout << "Input out of range, please make sure you only try removing what has already been ordered" << std::endl;
		//out of bounds
	}
}

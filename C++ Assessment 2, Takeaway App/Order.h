#pragma once
class Order
{
private:
	float total;

	float calculateTotal();
	std::string printReceipt();
	int toString();
};

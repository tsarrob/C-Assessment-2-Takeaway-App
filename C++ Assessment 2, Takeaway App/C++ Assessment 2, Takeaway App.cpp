#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "Item.h"

//READ ME
//PLEASE USE ISO C++ 17 LANGUAGE STANDARD 

//Written by Robert Lipodatenko

using namespace std;

int main()
{
	//creates menu from a csv file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();



	cout << menu.toString();
}


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


	while (true)
	{
		cout << "----------------------------Commands-----------------------------\n";
		cout << "1. Show menu \n";
		cout << "2. Add item to order \n";
		cout << "3. Remove item from order \n";
		cout << "4. Checkout \n";
		cout << "5. Help \n";
		cout << "6. Exit program \n";
		cout << "7. Add/Remove multiple items at once \n";
		cout << "8. Show menu by ascending/descending price order \n";
		cout << "-----------------------------------------------------------------\n";

		int user_choice; //users input



		//Error userinput handling
		while (true)
		{
			cout << "\nEnter a numbered command from the list: \n";
			cin >> user_choice;

			if (!cin)
			{
				cin.clear(); //resets failbit
				cin.ignore(INT_MAX, '\n'); //ignores all data that was inputted
				cout << "Invalid input, please enter a number\n";
			}
			else
			{
				break;
			}
		}


		switch (user_choice)
		{

		//viewing the menu normally
		case 1:

			cout << menu.toString();
			break;

		//Add item to order
		case 2:


			break;

		//remove item from order
		case 3:


			break;

		//checkout
		case 4:


			break;

		//help
		case 5:


			break;

		//exit program
		case 6:


			break;

		//add/remove multiple items at once
		case 7:


			break;


		//show menu by ascending/descending price order
		case 8:


			break;

		}
	}


	
}


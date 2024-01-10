#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "ItemList.h"
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
		cout << "\n\n----------------------------Commands-----------------------------\n";
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
		string checkOut;


		//for case 7
		vector<int> userInputs;
		string userInput;
		string number;
		string userInput7;
		
		//for care 8
		string userInput8;



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

		int itemNum = 0;
		switch (user_choice)
		{

		//viewing the menu normally
		case 1:
			cout << menu.toString();
			break;

		//Add item to order
		case 2:
			itemNum = 0;
			cout << "Input item number that you want to add to order: " << endl;
			cin >> itemNum;

			if (itemNum >= 1 && itemNum <= menu.getMenuSize())
			{
				Item* pickedItem = menu.getMenuItem(itemNum);
				order.addOrder(pickedItem);
				cout << pickedItem->getName() << " has been added to the order!" << endl;
				
			}
			else
			{
				cout << "Item not found\n";
			}

			break;

		//remove item from order
		case 3:
			itemNum = 0;
			cout << "Input item order number you want to remove: ";
			cin >> itemNum;

			order.removeOrder(itemNum);

			break;

		//checkout
		case 4:
			
			cout<<order.toString();
			cout<< "Do you want to Checkout and finish your order, input yes or no" << endl;
			cin >> checkOut;
			if (checkOut == "yes")
			{
				order.printReceipt();
				cout << "exiting program..." << endl;
				return false;
				break;
			}
			else
			{
				break;
			}

			break;

		//help
		case 5:
			cout << "---Help---" << endl;
			cout << "To order an item from the menu, input 2, to order a specific item from the menu input the number next to the item" << endl;
			cout << "to pay for your order and checkout, input 4, and further instructions will be given." << endl;
			cout << "to finish and exit using the program, input 6," << endl <<endl;

			break;

		//exit program
		case 6:

			cout << "exiting program..." << endl;
			return false;
			break;

		//add/remove multiple items at once
		case 7:

			cout << "Input \"add\" to add or \"remove\" to remove multiple items at once" << endl;
			cin >> userInput7;
			if (userInput7 == "add" || userInput7 =="remove")
			{
				cout << "Input multiple order items separated by individual spaces that u want to add/remove e.g. (2 3 5): " << endl;

				cin.ignore(); //make sure getline doesnt get skipped
				getline(cin, userInput);
				userInput += ' '; //stops overflow

				//converting users input to multiple inputs and error handling//
				for (size_t i = 0; i < userInput.size(); i++) //size_t unsigned type to stop the potential error
				{
					if (userInput[i] >= '0' && userInput[i] <= '9')
					{
						if (i + 1 == userInput.size() || userInput[i + 1] == ' ') //it wont overflow
						{
							number += userInput[i];
							userInputs.push_back(stoi(number)); //convers string to int
							number = "";
						}
						else
						{
							number += userInput[i];
						}

					}
					else
					{
						//skip
					}
				}

				//Adding
				if (userInput7 == "add")
				{
					//ordering multiple times
					for (int j = 0; j < userInputs.size(); ++j)
					{
						if (userInputs[j] >= 1 && userInputs[j] <= menu.getMenuSize())
						{
							Item* pickedItem = menu.getMenuItem(userInputs[j]);
							order.addOrder(pickedItem);
							cout << pickedItem->getName() << " has been added to the order!" << endl;

						}
					}
					
				}

				//Removing
				else
				{
					for (int j = 0; j < userInputs.size(); ++j)
					{
						order.removeOrder(userInputs[j]);
					}
					

				}


			}
			else
			{
				cout << "Invalid input, try again" << endl;
			}

			break;

		//show menu by ascending/descending price order
		case 8:
			cout << "Input 1 for ascending, input 2 for descending" << endl;
			cin >> userInput8;

			if (userInput8 == "1")
			{
				cout<<menu.toString2("1");
			}
			else if (userInput8 == "2")
			{
				cout<<menu.toString2("2");
			}
			else
			{
				cout << "invalid input, try again" << endl;
			}
			break;

		}
	}


	
}


#pragma once
#include <string>
#include <iostream>
class Item
{
public:
	
	Item(std::string name, double price, int calories); //constructor
	~Item(); //deconstructor

	//get functions
	int getCalories();
	std::string getName();
	double getPrice();
	

	//other functions
	std::string toString();


private:

	//private attributes
	int calories;
	std::string name;
	double price;
};


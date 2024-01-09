#pragma once
#include <string>
#include <iostream>
#include <sstream>
class Item
{
public:
	
	Item(std::string name, double price, int calories); //constructor
	~Item(); //deconstructor

	//get functions
	int getCalories();
	std::string getName();
	double getPrice();
	virtual char getType() = 0; //pure virtual function
	

	//other functions
	virtual std::string toString(); //virtual function


private:

	//private attributes
	int calories;
	std::string name;
	double price;
};


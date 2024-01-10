#pragma once
#include "ItemList.h"
#include <string>

class Menu: public ItemList
{
public:
	Menu(std::string textfile); //constructor
	~Menu(); //destructor

	//other functions
	void load(std::string textfile);//opens menu text file
	std::string toString();
	std::string toString2(std::string mode); //acending/decending 
	Item* getMenuItem(int index);
	int64_t getMenuSize();
	bool compareAscending(Item* item1, Item* item2);
	bool compareDescending(Item* item1, Item* item2);
};


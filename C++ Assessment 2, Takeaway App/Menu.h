#pragma once
#include "ItemList.h"
#include <string>

class Menu: public ItemList
{
public:
	Menu(std::string textfile); //constructor
	~Menu(); //destructor
	void load(std::string textfile);//opens menu text file
};


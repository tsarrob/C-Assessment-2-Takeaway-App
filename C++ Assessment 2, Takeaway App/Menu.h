#pragma once
#include <string>



class Menu
{
public:
	Menu(std::string textfile); //constructor
	void load(std::string textfile);//opens menu textfile
};


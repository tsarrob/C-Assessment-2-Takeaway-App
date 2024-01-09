#include "MainCourse.h"

//constructor
MainCourse::MainCourse(std::string name, double price, int calories)
	:Item(name, price, calories) {}

//get functions
char MainCourse::getType()
{
	return 'm';
}


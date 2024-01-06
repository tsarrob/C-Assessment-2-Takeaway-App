#pragma once
#include <vector>
class ItemList //Abstract class
{
public:
	std::vector<int> items;

	virtual void toString() = 0; //pure virtual function
};


#include "Menu.h"

//for reading a text file
#include <filesystem>
#include <iostream>
#include <fstream>

void Menu::load(std::string textfile) //opens menu text file
{
    std::string line;
    std::ifstream myfile(textfile);
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {
            std::cout << line << std::endl;
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";

}

Menu::Menu(std::string textfile) //constructor
{
	load(textfile);
}


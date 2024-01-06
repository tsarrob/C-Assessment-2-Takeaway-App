#include "Menu.h"

//for reading a text file
#include <iostream>
#include <fstream>
#include <filesystem> //used so I can get current working directory


void Menu::load(std::string textfile) //opens menu text file
{
    std::string line;
    std::ifstream myfile(std::filesystem::current_path().string() + "\\" + textfile); //Getting the file from filepath
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


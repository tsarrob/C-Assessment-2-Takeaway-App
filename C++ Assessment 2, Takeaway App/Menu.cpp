#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

#include <sstream>


//for reading a text file
#include <iostream>
#include <fstream>
#include <filesystem> //used so I can get current working directory

Menu::Menu(std::string textfile) //constructor
{
    load(textfile); //calls function to open and read text file
}

Menu::~Menu() //destructor
{
    //empty
}

std::string Menu::toString()
{
    std::ostringstream menuString; //used to build the string
    menuString << "---------Menu by Robert Lipodatenko---------" << std::endl;
    int j = 0;
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i]->getType() == 'a' and j == 0)
        {
            j = 1;
            menuString << "-----------------Appetisers-----------------" << std::endl;
        }
        if (items[i]->getType() == 'm' and (j == 0 || j ==1))
        {
            j = 2;
            menuString << "-----------------Main Course----------------" << std::endl;
        }
        if (items[i]->getType() == 'b' and (j == 0 || j ==1|| j==2))
        {
            j = 3;
            menuString << "-----------------Beverages------------------" << std::endl;
        }
        menuString << items[i]->toString() << std::endl;
    }
  



    return menuString.str(); //returns the completed string

}


void Menu::load(std::string textfile) //opens menu text file
{
    std::string line;
    std::ifstream myfile(std::filesystem::current_path().string() + "\\" + textfile); //Getting the file from filepath
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {

            //set to default
            char itemtype = 'O'; 
            std::string name = "";

            double price = 0.0;
            int calories = 0;
            bool shareable = false;
            bool twoForOne = false;

            double abv = 0.0;
            int volume = 0;

            int counter = 0; //counts the commas when parsing the lines of text
            std::string value = ""; //this is used to save the string once it reaches a comma to seperate the values

            //this updates the defualt variables from the csv accordingly
            for (int i = 0; i <= line.size() - 1; i++) {
                if (line[i] == ',' || i >= line.size() - 1) {

                    //uses the counter for the switch case
                    //c_str converts string to array of char, atof is to float, atoi is to integer
                    switch (counter) {

                    case 0: itemtype = value[0]; break;
                    case 1: name = value; break;
                    case 2: price = atof(value.c_str()); break;
                    case 3: calories = atoi(value.c_str()); break;
                    case 4: if (value == "y") {
                        shareable = true;} break;
                    case 5: if (value == "y") {
                        twoForOne = true;} break;
                    case 6: volume = atoi(value.c_str()); break;
                    case 7: abv = atof(value.c_str()); break;

                    }

                    value = ""; //resets value once comma or end of line is hit
                    counter += 1;
                }

                else {
                    value += line[i]; //adds the chars together to form a string when comma or end of line is not reached.
                }
            }

            //creates object according to the itemtype
            if (itemtype == 'a')
            {
                items.push_back(new Appetiser(name, price, calories, shareable, twoForOne));
            }
            else if (itemtype == 'm')
            {
                items.push_back(new MainCourse(name, price, calories));
            }
            else if (itemtype == 'b')
            {
                items.push_back(new Beverage(name, price, calories, abv, volume));
            }
            else
            {
                std::cout << "itemtype invalid or not found" << std::endl;
            }
            
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";

}




/*********************************************************************
** Program Filename: main.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-25
** Description: Main file for shopping list program
*********************************************************************/

//includes
#include <iostream>
#include <string>
#include "item.hpp"
#include "list.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;

void displayMenu();

int main()
{
	cout << "Welcome to the shopping list program." << endl;
	cout << endl;
	cout << "Press any key to contine.";
	cin.get();

	string response = "";

	cout << "Would you like to create a list? (Y or N)" << endl;
	cin >> response;

	if (response == "Y" || response == "y")
	{
		List itemList = List();

		cout << "An empty list has been created" << endl;
		cout << endl;

		int menuResponse = 0;
		while (menuResponse != 4)
		{
			if (menuResponse == 0) displayMenu();
			cin >> menuResponse;

			if (menuResponse == 1)   //add an item to the list
			{
				string name = "";
				string unit = "";
				int qty = 0;
				double priceEach = 0;

				//get item data
				cout << "Please enter the items name: ";
				cin >> name;
				cout << "Please enter the unit type (Each, Dozen, Case, Ounces, Pounds, Pint, Quart, Gallon, Other): " << endl;
				cin >> unit;
				cout << "Please enter the quantity to purchase (1-99): ";
				cin >> qty;
				cout << "Please enter the price each in this format XXX.XX: ";
				cin >> priceEach;

				//create the item
				Item itemToAdd = Item(name, unit, qty, priceEach);

				//add the item to the list
				itemList.addItem(itemToAdd);
				cout << "item has been added";
				cout << endl;
				displayMenu();
				//itemList.displayList();
				std::cin.get();
			}

			if (menuResponse == 2)	//delete an item
			{
				int positionToDelete = -1;
				itemList.displayList();

				//get the items array position
				if (positionToDelete = -1)
				{
					cout << "Enter the Position # of the item to delete:  ";
					cin >> positionToDelete;
					if ((positionToDelete >= 0) || (positionToDelete <= itemList.getArrayPosAvail()))
					{
						for (int i = positionToDelete; i < itemList.getArrayPosAvail(); i++)
						{
							Item temp = itemList.getItem(i + 1);
							itemList.overwriteItem(temp, i);
						}
						//reset position available in the array
						int newPosition = itemList.getArrayPosAvail() - 1;
						itemList.setArrayPosAvail(newPosition);

						cout << "Item has been deleted.";
						cout << endl;
						displayMenu();
					}
					else positionToDelete = -1;
				}
			}

			if (menuResponse == 3)
			{
				itemList.displayList();
				displayMenu();
			}
		}
	}
	else
	{
		cout << "Goodbye.";
	}

	return 0;
}

void displayMenu()
{
	cout << endl;
	cout << "**********************************************" << endl;
	cout << "*    Make your selection and press Enter     *" << endl;
	cout << "*       1  to add an item to the list        *" << endl;
	cout << "*       2  to delete an item from the list   *" << endl;
	cout << "*       3  to display the list               *" << endl;
	cout << "*       4  to quit the program               *" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
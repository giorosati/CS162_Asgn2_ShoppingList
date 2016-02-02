/*********************************************************************
** Program Filename: list.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-25
** Description: Implementation file for List class
*********************************************************************/

//includes
#include <iomanip>
#include "list.hpp"

//usings
using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;
using std::left;
using std::right;
using std::setw;

//default constructor
List::List()
{
	Item* arrayOfItems = new Item[4];
	arrayPosAvail = 0;
	arrayCapacity = 4;
}

//used to increase the size of the array
void List::expandList()
{
	Item* tempArray = new Item[arrayCapacity];

	for (int i = 0; i < arrayCapacity; i++)
	{
		tempArray[i] = arrayOfItems[i];
	}

	delete[] arrayOfItems;

	arrayCapacity = arrayCapacity + 4;
	Item* arrayOfItems = new Item[arrayCapacity];

	for (int i = 0; i < arrayCapacity - 4; i++)
	{
		arrayOfItems[i] = tempArray[i];
	}

	delete[] tempArray;
}

//deconstructor
List::~List()
{
	//cout << "list deconstructor has run" << endl;
}

//add an item
void List::addItem(Item itemIn)
{
	if (arrayPosAvail == arrayCapacity)
	{
		expandList();
		//cout << "expand list has run";
		//system("pause");
	}
	arrayOfItems[arrayPosAvail] = itemIn;
	arrayPosAvail = arrayPosAvail + 1;
}

//overwrite an item
void List::overwriteItem(Item itemIn, int position)
{
	arrayOfItems[position] = itemIn;
}

//remove an Item
void List::removeItem(Item itemIn)
{
	int position = getItemPosition(itemIn);
	if (position != -1)
	{
		for (int i = position; i < arrayCapacity - 1; i++)
		{
			arrayOfItems[position] = arrayOfItems[position + 1];
		}
		arrayPosAvail = arrayPosAvail - 1;
	}
}

//get an item's position in the array
int List::getItemPosition(Item itemIn)
{
	for (int i = 0; i < arrayPosAvail; ++i)
	{
		if (this->arrayOfItems[i].getItemName() == itemIn.getItemName()) return i;
		else return -1;
	}
}

//get next available position in the array
int List::getArrayPosAvail()
{
	return arrayPosAvail;
}

//set array position availble
void List::setArrayPosAvail(int position)
{
	arrayPosAvail = position;
}

//get an item from the array
Item List::getItem(int arrayPosition)
{
	Item temp = arrayOfItems[arrayPosition];
	return temp;
}

//display the list
void List::displayList()
{
	cout << endl;
	cout << endl;

	double grandTotal = 0;
	cout << "Position  " << "Item Name________________  " << "Qty__  " << "  $ Each   " << "Total_$" << endl;
	for (int i = 0; i < arrayPosAvail; i++)
	{
		Item item = arrayOfItems[i];
		double lineTotal = item.getItemQty() * item.getItemPrice();
		cout << setw(10) << left << i;

		cout << setw(28) << left << item.getItemName();
		cout << setw(4) << right << fixed << showpoint << setprecision(2) << item.getItemQty();
		cout << setw(10) << right << fixed << showpoint << setprecision(2) << item.getItemPrice();
		cout << setw(10) << right << lineTotal << endl;
		grandTotal = grandTotal + lineTotal;
	}
	cout << endl;
	cout << "Total for these items will be:  $ " << grandTotal << endl;
	cout << endl;
	cout << endl;
}
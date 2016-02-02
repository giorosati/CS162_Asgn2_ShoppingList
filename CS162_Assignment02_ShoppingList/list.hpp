/*********************************************************************
** Program Filename: list.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-25
** Description: Header file for list.cpp
*********************************************************************/
#ifndef LIST_HPP
#define LIST_HPP

//includes
#include <iostream>
#include <string>
#include "item.hpp"

//usings
using std::string;

class List
{
private:
	Item arrayOfItems[4];
	int arrayPosAvail;
	int arrayCapacity;

public:
	List();					//default constructor
	~List();				//deconstructor
	void expandList();		//increase size of array. Makes a new larger array, copies data, deletes old array

	//getters
	int getItemPosition(Item);
	int getArrayPosAvail();
	Item getItem(int arrayPosition);

	//setters
	void setArrayPosAvail(int);		//sets the arrayPosAvail value

	//adding & removing items
	void overwriteItem(Item, int);	//replaces an item in the array
	void addItem(Item);				//add item to the array
	void removeItem(Item);			//remove an item from the array

	//display
	void displayList();			//output the list
};

#endif
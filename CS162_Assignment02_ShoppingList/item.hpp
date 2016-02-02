/*********************************************************************
** Program Filename: item.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-25
** Description: Header file for item.cpp
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

//includes
#include <iostream>

//usings
using std::string;

class Item
{
private:
	string name;
	string unit;
	int qty;
	double unitPrice;

public:
	//function prototypes
	Item();								 //default constructor
	Item(string, string, int, double);	//constructor with parameters
	~Item();							//deconsturtor

	//getters
	string getItemName();
	double getItemPrice();
	int getItemQty();
};

#endif
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
	enum unit {Can, Box, Ounces, Pounds, Case};
	int qty;
	double unitPrice;
};


//function prototypes
Item();
~Item();


//getters


//setters


#endif
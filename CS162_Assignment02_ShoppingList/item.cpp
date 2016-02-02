/*********************************************************************
** Program Filename: item.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-25
** Description: Implementation file for Item class
*********************************************************************/

//includes

#include "item.hpp"

//usings
using std::string;
using std::cout;
using std::endl;

//default constructor
Item::Item()
{
	name = "";
	unit = "";
	qty = 0;
	unitPrice = 0;
}
Item::Item(string nameIn, string unitIn, int qtyIn, double unitPriceIn)
{
	name = nameIn;
	unit = unitIn;
	qty = qtyIn;
	unitPrice = unitPriceIn;
}

//deconstructor
Item::~Item()
{
	//cout << "item deconstructor has run" << endl;
}

//get name
string Item::getItemName()
{
	return name;
}

//get qty
int Item::getItemQty()
{
	return qty;
}

//get price each
double Item::getItemPrice()
{
	return unitPrice;
}
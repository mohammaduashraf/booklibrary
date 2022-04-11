/*
 * Name:
 */
#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Item {
protected:

	/* holds the item's id */
	int id;

	/* holds the item's price*/
	double price;

	/* holds the item's title
	 * For this assignment we will assume that all
	 * titles are exactly 18 characters long
	 */
	string title;

public:

	static const int TITLE_NUM_BYTES = 18;

	/* Copy constructor performs member-wise copy */
	Item(const Item& other)
	{
		id = other.getId();
		price = other.getPrice();
		title = other.getTitle();
	}

	/* Create an instance from the parameter values. */
	Item(const int id, const string title, const double price)
	{
		this->id = id;
		this->title = title;
		this->price = price;
	}

	/* Performs member-wise copy */
	Item& operator=(const Item& other)
	{
		Item k(other.getId(), other.getTitle(), other.getPrice());
		return k = other;
	}
	/* getter for ID */
	long getId() const
	{
		return id;
	}

	/* getter for price */
	double getPrice() const
	{
		return price;
	}

	/* getter for title */
	string getTitle() const
	{
		return title;
	}

	/**
	 * Reads values from the command prompt in the following order
	 * 1. id
	 * 2. title
	 * 3. price
	 *
	 * Hint: invoke this from the derived class' operator>>
	 */
	friend istream& operator>>(istream& in, Item& item)
	{
		in >> item.id >> item.title >> item.price;
		return in;
	}
	/**
	 * Prints values from the command prompt in the following order
	 * 1. id
	 * 2. title
	 * 3. price
	 *
	 * Hint: invoke this from the derived class' operator<<
	 */
	friend ostream& operator<<(ostream& out, const Item& item)
	{

		out << item.id << " " << item.title << " " << item.price;
		return out;
	}
};

#endif /* ITEM_H_ */

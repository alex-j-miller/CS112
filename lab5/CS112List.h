/*
 * CS112List.h
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <string>
using namespace std;

typedef string Item;

class CS112List {
public:
	CS112List();
	CS112List(int size);
	CS112List(const CS112List &orig); // copy ctor
	virtual ~CS112List();

	// getters
	int getSize() const;
	Item getValue(int index) const;
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);

	// others
	void append(const Item &value);
	int find(Item search) const;

	CS112List & operator+(const CS112List &rhs) const;

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
	int validate_index(int index) const;
};

// make it so we can do cout << aList.
ostream& operator<<(ostream &out, const CS112List &rhs);

#endif /* CS112LIST_H_ */

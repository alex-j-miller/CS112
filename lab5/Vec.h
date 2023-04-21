/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <fstream>
using namespace std;

//typedef double Item;
template <class Item>

class Vec {
public:
	//constructers and destructors
	Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	virtual ~Vec();

	//getters
	unsigned getSize() const;
	Item getItem(unsigned index) const;

	//setters
	void setItem(unsigned index, const Item& it);
	void setSize(unsigned newSize);

	//operators
	Vec<Item>& operator=(const Vec<Item>& original);
	Item& operator[](int index);
	bool operator==(const Vec<Item>& v2) const;
	Vec operator+(const Vec<Item> rhs);
	Vec operator-(const Vec<Item> rhs);

	void writeTo(ostream& out) const;
	void readFrom(istream& in);

private:
	Item * myArray;
	unsigned mySize;
	friend class VecTester;
};

template <class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

template <class Item>
Vec<Item>::Vec(unsigned size) {
	if(size > 0 ) {
		myArray = new Item[size]();
		mySize = size;
	} else {
		myArray = nullptr;
		mySize = 0;
	}
}

template <class Item>
Vec<Item>::Vec(const Vec<Item>& original){
	mySize = original.mySize;
	if(original.mySize > 0){
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (myArray == original.myArray) {
		return *this;
	}
	delete [] myArray;
	mySize = original.mySize;
	if(original.mySize > 0){
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
	return *this;
}

template <class Item>
Item& Vec<Item>::operator[](int index) {
	if (index < 0 or index >= mySize) {
		throw range_error("Invalid index");
	}
	return myArray[index];
}

template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item> rhs) {
	if (mySize != rhs.mySize) {
		throw invalid_argument("Vectors are not the same size.");
	}
	Vec<Item> result(mySize + rhs.mySize);
	for (unsigned i = 0; i < mySize; i++) {
		result[i] = myArray[i] + rhs.myArray[i];
	}
	return result;
}

template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item> rhs) {
	if (mySize != rhs.mySize) {
		throw invalid_argument("Vectors are not the same size.");
	}
	Vec<Item> result(mySize + rhs.mySize);
	for (unsigned i = 0; i < mySize; i++) {
		result[i] = myArray[i] - rhs.myArray[i];
	}
	return result;
}

template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if(index >= mySize or index < 0) {
		throw range_error("Invalid Index");
	}
	myArray[index] = it;
}

template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if(index >= mySize or index < 0) {
		throw range_error("Invalid Index");
	}
	return myArray[index];
}

template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {//1
			delete [] myArray; //a
			myArray = nullptr;//b
			mySize = 0; //c

		}else {//2
			Item *newArray = new Item[newSize]();//a
			if (mySize < newSize) {//b
				for (unsigned i = 0; i < mySize; i++) {//i
					newArray[i] = myArray[i];
				}

			} else {//otherwise
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize; //c
			delete [] myArray; //d
			myArray = newArray; //e
		}
	}
}

template <class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for(unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

template <class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

template <class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

#endif /*VEC_H_*/



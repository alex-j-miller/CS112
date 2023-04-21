/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"
#include <stdexcept>
using namespace std;

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

Vec::Vec(unsigned size) {
	if(size > 0 ) {
		myArray = new Item[size]();
		mySize = size;
	} else {
		myArray = nullptr;
		mySize = 0;
	}
}

Vec::Vec(const Vec& original){
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

Vec& Vec::operator=(const Vec& original) {
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

Item& Vec::operator[](int index) {
	if (index < 0 or index >= mySize) {
		throw range_error("Invalid index");
	}
	return myArray[index];
}

Vec Vec::operator+(const Vec rhs) {
	if (mySize != rhs.mySize) {
		throw invalid_argument("Vectors are not the same size.");
	}
	Vec result(mySize + rhs.mySize);
	for (unsigned i = 0; i < mySize; i++) {
		result[i] = myArray[i] + rhs.myArray[i];
	}
	return result;
}

Vec Vec::operator-(const Vec rhs) {
	if (mySize != rhs.mySize) {
		throw invalid_argument("Vectors are not the same size.");
	}
	Vec result(mySize + rhs.mySize);
	for (unsigned i = 0; i < mySize; i++) {
		result[i] = myArray[i] - rhs.myArray[i];
	}
	return result;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if(index >= mySize or index < 0) {
		throw range_error("Invalid Index");
	}
	myArray[index] = it;
}

Item Vec::getItem(unsigned index) const {
	if(index >= mySize or index < 0) {
		throw range_error("Invalid Index");
	}
	return myArray[index];
}

void Vec::setSize(unsigned newSize) {
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

bool Vec::operator==(const Vec& v2) const {
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

void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

Vec::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

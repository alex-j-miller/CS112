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

//typedef string Item;
template <class Item>

class CS112List {
public:
	CS112List();
	CS112List(int size);
	CS112List(const CS112List<Item> &orig); // copy ctor
	virtual ~CS112List();

	// getters
	int getSize() const;
	Item getValue(int index) const;
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);
	void insert(int index, const Item &it);
	bool remove(Item it);
	Item removeAt(int index);

	// others
	void append(const Item &value);
	int find(Item search) const;

	CS112List<Item> & operator+(const CS112List<Item> &rhs) const;

	// make it so we can do cout << aList.
	ostream& operator<<(ostream &out);

	//slice
	CS112List<Item>& slice(int start_index, int stop_index, unsigned step_index);
	CS112List<Item>& slice(int start_index, int stop_index);
	CS112List<Item>& slice(int stop_index);
private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
	int validate_index(int index) const;


};



#endif /* CS112LIST_H_ */

template <class Item>
CS112List<Item>::CS112List() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

template <class Item>
CS112List<Item>::CS112List(int size) {
	mySize = myCapacity = size;
	myArray = new Item[size]();
}

template <class Item>
CS112List<Item>::CS112List(const CS112List<Item> &orig) {
	// cout << "copy ctor called with object " << &orig << endl;
	mySize = orig.mySize;
	myCapacity = orig.myCapacity;
	if (myCapacity == 0) {
		myArray = nullptr;
	} else {
		// deep copy.
		myArray = new Item[mySize]();
		for (int i = 0; i < mySize; i++) {
			myArray[i] = orig.myArray[i];
		}
	}
}

// called when object goes out of scope.
template <class Item>
CS112List<Item>::~CS112List() {
	delete [] myArray;
}

template <class Item>
void CS112List<Item>::append(const Item &value) {
    if (mySize >= myCapacity) {
        // Note: double the capacity, unless it was 0, then make it 1.
        int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
        Item *tmp = new Item[newCapacity]();
        for (int i = 0; i < mySize; i++) {
            tmp[i] = myArray[i];
        }
        myCapacity = newCapacity;
        delete[] myArray;
        myArray = tmp;
    }
    myArray[mySize] = value;
    mySize++;
}

template <class Item>
int CS112List<Item>::getSize() const {
	return mySize;
}

template <class Item>
Item CS112List<Item>::getValue(int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
void CS112List<Item>::setValue(int index, const Item &value) {
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range");
	}
	myArray[validate_index(index)] = value;
}

// return a reference to the index-th location.
template <class Item>
Item & CS112List<Item>::operator[](int index) const {
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range");
	}
	return myArray[validate_index(index)];
}

template <class Item>
CS112List<Item> & CS112List<Item>::operator+(const CS112List<Item> &rhs) const {
	CS112List *result = new CS112List(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

template <class Item>
ostream& CS112List<Item>::operator<<(ostream &out) {
	out << "[";
	for (int i = 0; i < mySize; i++) {
		out << this[i];
		if (i < mySize - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;
}

template <class Item>
int CS112List<Item>::validate_index(int index) const {
	if (index >= mySize) {
		throw range_error("Invalid Index 1");
	}
	if (index <= -mySize) {
		throw range_error("Invalid Index 2");
	}

	if (index < 0) {
		return mySize + index;
	}
	return index;
}

template <class Item>
int CS112List<Item>::find(Item search) const {
	for (unsigned i = 0; i < mySize; i++) {
		if(myArray[i] == search) {
			return i;
		}
	}
	return -1;
}

template <class Item>
void CS112List<Item>::insert(int index, const Item &it) {
//	 index = validate_index(index);

	// shift up
	for(int i = mySize - 1; i > index; i--) {
		setValue(i, getValue(i-1));
	}

	// insert new item at the index
	setValue(index, it);
	mySize++;
}

template <class Item>
bool CS112List<Item>::remove(Item it) {
	// find the index
	int index = find(it);

	//if not in list return false
	if(index == -1) {
		return false;
	}

	//shift down
	for(int i = index; i < mySize - 1; i++) {
		setValue(i, getValue(i+1));
	}
	setValue(mySize - 1, 0);

	mySize--;
	return true;
}

template <class Item>
Item CS112List<Item>::removeAt(int index) {
	Item saved = myArray[index];

	//shift down
	for(int i = index; i < mySize - 1; i++) {
		setValue(i, getValue(i+1));
	}
	setValue(mySize - 1, 0);

	mySize--;
	return saved;
}

template <class Item>
CS112List<Item>& CS112List<Item>::slice(int start_index, int stop_index, unsigned step_index) {
	if(step_index == 0) {
		throw invalid_argument("Cannot step 0 indexes");
	}

	CS112List<Item> *result = new CS112List;
	for(int i = start_index; i < stop_index; i += step_index) {
		result -> append(myArray[i]);
	}
	return *result;
}

template <class Item>
CS112List<Item>& CS112List<Item>::slice(int stop_index) {
	return slice(0, stop_index, 1);
}

template <class Item>
CS112List<Item>& CS112List<Item>::slice(int start_index, int stop_index) {
	return slice(start_index, stop_index, 1);
}

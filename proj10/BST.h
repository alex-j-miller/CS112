/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

//typedef int Item;
template <class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

	void insert(Item it);
	bool contains(Item it);

	int getHeight();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();

            void insert(Item& it);
            bool contains(Item& it);

            int getHeight();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

#endif /*BST_H_*/

template <class Item>
BST<Item>::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
bool BST<Item>::contains(Item it) {
	if (myNumItems == 0) {
		return false;
	}
	return myRoot->contains(it);
}

template <class Item>
bool BST<Item>::Node::contains(Item& it) {
	if (myItem == it) {
		return true;
	} else {
		if (it < myItem) {
			if(myLeft == nullptr) {
				return false;
			} else {
				return myLeft->contains(it);
			}
		} else if (it > myItem) {
			if(myRight == nullptr) {
				return false;
			} else {
				return myRight->contains(it);
			}
		}
	}
	return false;
}

template <class Item>
void BST<Item>::insert(Item it) {
	if (myNumItems == 0) { // checking to see if the BST is empty
		myRoot = new Node(it);
	} else {
		myRoot->insert(it);
	}
	myNumItems++;
}

template <class Item>
void BST<Item>::Node::insert(Item& it) {
	if (it < myItem) {
		if (myLeft == nullptr){
			myLeft = new Node(it);
		} else {
			myLeft->insert(it);
		}
	}
	if (it > myItem) {
		if (myRight == nullptr) {
			myRight = new Node(it);
		} else {
			myRight->insert(it);
		}
	}
	if (it == myItem) {
		throw Exception("BST::Node::insert()", "Redundant Item");
	}
}

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::traversePostorder() {
	if (!isEmpty()) {
		myRoot->traversePostorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft->traversePostorder();
	}
	if (myRight != nullptr) {
		myRight->traversePostorder();
	}

	processItem();
}

template <class Item>
void BST<Item>::traverseInorder() {
	if (!isEmpty()) {
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft->traverseInorder();
	}
	processItem();

	if (myRight != nullptr) {
		myRight->traverseInorder();
	}

}

template <class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

template <class Item>
int BST<Item>::getHeight() {
	if (myNumItems == 0) {
		return 0;
	}
	return myRoot->getHeight();
}

template <class Item>
int BST<Item>::Node::getHeight() {
	int leftH;
	int rightH;

	if (myLeft == nullptr) {
		leftH = 0;
	} else {
		leftH = myLeft->getHeight();
	}

	if (myRight == nullptr) {
		rightH = 0;
	} else {
		rightH = myRight->getHeight();
	}

	return (leftH > rightH) ? leftH + 1: rightH + 1;
}


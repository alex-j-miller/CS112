/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 */

#include "BST.h"

BST::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

bool BST::contains(Item it) {
	if (myNumItems == 0) {
		return false;
	}
	return myRoot->contains(it);
}

bool BST::Node::contains(Item& it) {
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


void BST::insert(Item it) {
	if (myNumItems == 0) { // checking to see if the BST is empty
		myRoot = new Node(it);
	} else {
		myRoot->insert(it);
	}
	myNumItems++;
}

void BST::Node::insert(Item& it) {
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

BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

void BST::traversePostorder() {
	if (!isEmpty()) {
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft->traversePostorder();
	}
	if (myRight != nullptr) {
		myRight->traversePostorder();
	}

	processItem();
}

void BST::traverseInorder() {
	if (!isEmpty()) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft->traverseInorder();
	}
	processItem();

	if (myRight != nullptr) {
		myRight->traverseInorder();
	}

}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}



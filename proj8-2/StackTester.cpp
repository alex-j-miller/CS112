/*
 * StackTester.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: Alex
 */

#include "StackTester.h"
#include "Stack.h"
#include <cassert>
#include <iostream>

using namespace std;

StackTester::StackTester() {

}

void StackTester::run() {
	cout << "Testing..." << endl;
	testGetSize();
	testGetCapacity();
	testSetCapacity();


	cout << "All Tests Passed!" << endl;
}

void StackTester::testGetSize() {
	cout << "Testing getSize()... " << flush;
	Stack<int> s(100);
	assert(s.getSize() == 0);
	cout << "0 " << flush;
	for(int i = 0; i < 10; i++) {
		s.push(i);
	}
	assert(s.getSize() == 10);
	cout << "1 " << flush;

	cout << "Tests Passed" << endl;

}

void StackTester::testGetCapacity() {
	cout << "Testing getCapacity()... " << flush;
	Stack<int> s1(1);
	assert(s1.getCapacity() == 1);
	cout << "0 " << flush;

	Stack<int> s2(100);
	assert(s2.getCapacity() == 100);
	cout << "1 " << flush;

	cout << "Tests Passed" << endl;
}

void StackTester::testSetCapacity() {
	cout << "Testing setCapacity()... " << flush;
	Stack<int> s1(1);
	s1.setCapacity(10);
	assert(s1.getCapacity() == 10);
	cout << "0 " << flush;

	for(int i = 0; i < 5; i++) {
		s1.push(i);
	}

	cout << "1 " << flush;

	s1.setCapacity(6); // error here

	cout << "2 " << flush;
	assert(s1.myArray[0] == 0);
	cout << "3 " << flush;

	cout << "Tests Passed" << endl;
}

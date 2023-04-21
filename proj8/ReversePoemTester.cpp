/*
 * ReversePoemTester.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: alex
 */

#include "ReversePoemTester.h"
#include <iostream>
#include <cassert>

using namespace std;

ReversePoemTester::ReversePoemTester() {
	// TODO Auto-generated constructor stub
}
void ReversePoemTester::run() {
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetReverseBody();
}

void ReversePoemTester::testGetTitle() {
	cout << "Testing getTitle()... " << flush;
	ReversePoem r1("cats.txt");
	cout << "Cats == " << r1.getTitle() << flush;

	cout << "Tests Passed! " << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "Testing getAuthor()... " << flush;
	ReversePoem r1("cats.txt");
	cout << "Leo J. Smada == " << r1.getAuthor() << flush;

	cout << "Tests Passed! " << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "Testing getBody()... " << flush;
	ReversePoem r1("cats.txt");
	cout << "I love it when cats rub against me.\n I could never say \nI hate those purring felines. == " << r1.getBody() << flush;

	cout << "Tests Passed! " << endl;
}

void ReversePoemTester::testGetReverseBody() {
	cout << "Testing getBodyReversed()... " << flush;
	ReversePoem r1("cats.txt");
	cout << "I hate those purring felines.\n I could never say \n I love it when cats rub against me. == " << r1.getBodyReversed() << flush;

	cout << "Tests Passed! " << endl;
}


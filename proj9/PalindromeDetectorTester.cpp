/*
 * PalindromeDetectorTester.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Alex
 */

#include "PalindromeDetectorTester.h"
#include <cassert>
#include <iostream>

using namespace std;

PalindromeDetectorTester::PalindromeDetectorTester() {

}

void PalindromeDetectorTester::run() {
	isPalindromeTest();
}

void PalindromeDetectorTester::isPalindromeTest() {
	cout << "Testing isPalindrome() ... " << flush;

	PalindromeDetector pd;
	assert(pd.isPalindrome("A man, a plan, a canal, Panama!"));
	cout << "0 " << flush;

	assert(!pd.isPalindrome(""));
	cout << "1 " << flush;

	cout << "Tests Passed!" << endl;

}


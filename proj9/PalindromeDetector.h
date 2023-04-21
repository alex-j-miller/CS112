/*
 * PalindromeDetector.h
 *
 *  Created on: Mar 24, 2022
 *      Author: Alex
 */

#include <string>
#include <iostream>
#include <fstream>
#include "Stack.h"
#include "ArrayQueue.h"


using namespace std;

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

class PalindromeDetector {
public:
	PalindromeDetector();
	void detectPalindromes(string finName, string foutName);
	bool isPalindrome(string palindrome);
};

#endif /* PALINDROMEDETECTOR_H_ */

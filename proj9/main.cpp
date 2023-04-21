/*
 * main.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Alex
 */
#include <iostream>
#include "PalindromeDetector.h"

using namespace std;


int main() {
	PalindromeDetector p;
	p.detectPalindromes("palindrome.txt", "palindrome-1.txt");
	cout << "Finished!" << endl;

}




/*
 * main.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: alex
 */

#include <cassert>
#include <iostream>
#include "HighScores.h"
using namespace std;

int main() {

	// Tests getNumScores()
	HighScores h1;
	assert(h1.getNumScores() == 0);

	//Testing addScore
	h1.addScore(30);
	assert(h1.getNumScores() == 1);

	//Testing the getNumScores maximum
	for(int i = 0; i < 11; i++) {
		h1.addScore(i);
	}
	assert(h1.getNumScores() == 10);

	//Testing the range of getScore
	try {
		h1.getScore(11);
		assert(false);
	} catch (const invalid_argument &ie) {
		assert(true);
	}

	//Testing the ordering of addScore
	h1.addScore(1000);
	assert(h1.getScore(0) == 1000);
	h1.addScore(500);
	assert(h1.getScore(1) == 500);

	cout << "All tests passed!" << endl;
	return 0;
}



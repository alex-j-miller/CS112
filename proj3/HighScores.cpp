/*
 * HighScores.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: alex
 */

#include "HighScores.h"
#include <stdexcept>
#include <iostream>
using namespace std;

HighScores::HighScores() {

	//Getting default values
	myNumScores = 0;
	for(int i = 0; i < 10; i++) {
		myScores[i] = 0;
	}

}

int HighScores::getNumScores() {
	return myNumScores;
}
int HighScores::getScore(int index) {

	//making sure the index value us valid
	if(index >= 0 and index <= 9) {
		return myScores[index];
	} else {
		throw invalid_argument("Bad index value");
	}

}

void HighScores::addScore(int aScore) {

	int index = findLocationToInsert(aScore);

	if(index != -1) {
		HighScores::shiftUp(index);

		//inserting the new score
		myScores[index] = aScore;

		//incrementing the number of scores
		if (myNumScores < 10) {
			myNumScores++;
		}
	}



	//	if (myNumScores < 10){
	//		myScores[myNumScores] = aScore;
	//		myNumScores++;
	//	} else {
	//		return;
	//	}

}

int HighScores::findLocationToInsert(int newScore) {

	int index = -1;
	for(int i = 9; i >= 0; i--) {
		if(myScores[i] < newScore) {
			index = i;
		}
	}
	return index;
}

void HighScores::shiftUp(int fromIndex) {

	for(int i = 9; i > fromIndex; i--) {
		myScores[i] = myScores[i - 1];
	}
}


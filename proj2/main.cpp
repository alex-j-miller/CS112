/*
 * main.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: Alex
 */
#include <iostream>
using namespace std;

int main() {

	int SIZE;
	while (true) {
		//Get the size from the user
		cout << "Size for magic square: ";
		cin >> SIZE;
		if (SIZE % 2 != 0) {
			break;
		} else {
			cout << "Size needs to be even." << endl;
		}
	}

	int magic[15][15];

	// get default values for the entire matrix
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			magic[i][j] = 0;
		}
	}

	//Get the first position for 1
	int ROW = 0;
	int COL = SIZE / 2;

	//Make the magic square
	for (int i = 1; i <= (SIZE * SIZE); i++) {

		//Testing to see if the space is open and if not moving to the correct place
		if (magic[ROW][COL] == 0) {

			// set the current number
			magic[ROW][COL] = i;
		} else {
			ROW = ROW + 2;
			COL--;
			magic[ROW][COL] = i;
		}

		//Test to see if we are in the top right corner, if so move down one
		if (ROW == 0 and COL == (SIZE - 1)) {
			ROW++;
		} else {

			//if on the top row we move it to the bottom otherwise move up
			if (ROW == 0) {
				ROW = SIZE - 1;
			} else {
				ROW--;
			}

			//if we are on the far right move to the far left otherwise continue right
			if (COL == (SIZE - 1)) {
				COL = 0;
			} else {
				COL++;
			}
		}
	}

	//Print the magic square
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << magic[i][j] << " ";
		}
		cout << endl;
	}
}

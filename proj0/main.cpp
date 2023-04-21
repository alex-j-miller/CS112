/*
 * main.cpp
 *
 *  Created on: Jan 16, 2022
 *      Author: alex
 */

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	float array[20];
	cout << sizeof(array) << endl;

	float* seventh = &array[6];
	*seventh = 17.771;
	cout << array[6] << endl;
	cout << seventh << endl;

}



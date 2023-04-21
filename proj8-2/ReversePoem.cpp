/*
 * ReversePoem.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: alex
 */

#include "ReversePoem.h"
#include <iostream>
#include <fstream>
using namespace std;

ReversePoem::ReversePoem(string& filename) {
	Poem = new Stack<string>(1);
	ifstream file;
	file.open(filename);
	getline(file, myTitle);
	getline(file, myAuthor);


	string x;
	getline(file, x);
	while(getline(file, x)) {
		try {
			Poem->push(x);
			rPoem += x + "\n";
		} catch(StackException &) {
			Poem->setCapacity(Poem->getCapacity() * 2);
			Poem->push(x);
			rPoem += x + "\n";
		}
	}
	file.close();

	while(!Poem->isEmpty()) {
		poem +=  Poem->pop() + "\n";
	}

}

string ReversePoem::getTitle() {
	return myTitle;
}

string ReversePoem::getAuthor() {
	return myAuthor;
}

string ReversePoem::getBody() {
	return poem;
}

string ReversePoem::getBodyReversed() {
	return rPoem;
}


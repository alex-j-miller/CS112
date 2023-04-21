/*
 * ReversePoem.h
 *
 *  Created on: Mar 21, 2022
 *      Author: alex
 */

#include <string>
#include "Stack.h"
#include <fstream>
using namespace std;

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

class ReversePoem {
public:
	ReversePoem(string filename);
	string getTitle();
	string getAuthor();
	string getBody();
	string getBodyReversed();

private:
	string myTitle;
	string myAuthor;
	Stack<string> *Poem;
	string rPoem;
	string poem;
};

#endif /* REVERSEPOEM_H_ */

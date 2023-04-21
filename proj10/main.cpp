#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

void makeTree(string fileName) {
	ifstream f;
	f.open(fileName);

	string x;
	BST<string> bst;
	unsigned dupe = 0;

	while (getline(f, x)){
		try {
			bst.insert(x);
		} catch (Exception&){
			dupe++;
		}
	}

	f.close();

	cout << "Height = " << bst.getHeight() << endl;
	cout << "Dupes = " << dupe << endl;
}

int main() {
	makeTree("randomInts01.txt");
	makeTree("randomInts02.txt");
	makeTree("randomInts03.txt");
	makeTree("randomInts04.txt");
	makeTree("randomInts05.txt");
	makeTree("randomInts06.txt");
	makeTree("randomInts07.txt");
	makeTree("randomInts08.txt");
	makeTree("randomInts09.txt");
	makeTree("randomInts10.txt");

}



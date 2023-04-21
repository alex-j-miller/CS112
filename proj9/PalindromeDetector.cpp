/*
 * PalindromeDetector.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Alex
 */

#include "PalindromeDetector.h"

PalindromeDetector::PalindromeDetector() {

}

void PalindromeDetector::detectPalindromes(string finName, string foutName) {
	// setting up the streams
	ifstream fin;
	fin.open(finName);
	ofstream fout;
	fout.open(foutName);

	// reading the lines and seeing if they are palindromes
	string line;
	while(getline(fin, line)) {
		fout << line << flush;
		if (isPalindrome(line)) {
			fout << " *** "; // adding asterisks if line is a palindrome
		}
		fout << endl;
	}
	//closing the streams
	fin.close();
	fout.close();
}
bool PalindromeDetector::isPalindrome(string palindrome) {
	if (palindrome == "") { // checking if blank line
		return false;
	}
	// setting up the stack and queue
	Stack<char> s(1);
	ArrayQueue<char> q(1);
	char x;
	for(unsigned i = 0; i < palindrome.length(); i++) {
		// checking if in the right conditions
		if (isalpha(palindrome[i])) {
			x = tolower(palindrome[i]);

			// pushing to stack
			try {
				s.push(x);
			} catch (StackException&) {
				s.setCapacity(s.getCapacity() * 2);
				s.push(x);
			}

			// appending to queue
			try {
				q.append(x);
			} catch (FullQueueException&) {
				q.setCapacity(q.getCapacity() * 2);
				q.append(x);
			}
		}
	}
	// checking to see if the letters match
	for (unsigned i = 0; i < s.getSize(); i++) {
		if (s.pop() != q.remove()){
			return false;
		}
	}
	return true;
}


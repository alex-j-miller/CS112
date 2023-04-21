/*
 * main.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: Alex
 */

   /* main.cpp
    * ...
    */

   #include "ReversePoem.h"
   #include <iostream>
   using namespace std;

   int main() {
      cout << "\nEnter the name of the poem file: ";
      string poemFile;
      cin >> poemFile;

      ReversePoem reversePoem(poemFile);
      cout << reversePoem.getTitle() << "\n"
           << reversePoem.getAuthor() << "\n"
           << "\n*** Top-To-Bottom ***\n\n"
           << reversePoem.getBody()
           << "\n*** Bottom-To-Top ***\n\n"
           << reversePoem.getBodyReversed()
           << endl;
   }


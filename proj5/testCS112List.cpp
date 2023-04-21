/*
 * main.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#include <cassert>
#include <iostream>

#include "CS112List.h"
using namespace std;

int main() {
	cout << "Testing insert()... ";
	CS112List<int> l1(5);
	l1[0] = 1;
	l1[1] = 2;
	l1[2] = 3;
	l1.insert(0, 0);
	assert(l1[0] == 0);
	cout << "1 ";
	assert(l1[3] == 3);
	cout << "Passed!" << endl;

	cout << "Testing remove()... ";
	l1.remove(0);
	assert(l1[0] == 1);
	cout << "1 ";
	assert(l1[1] == 2);
	cout << "Passed!" << endl;

	cout << "Testing removeAt()... ";
	l1.removeAt(0);
	assert(l1[0] == 2);
	cout << "Passed!" << endl;

	cout << "Testing slice()... ";
	CS112List<int> l2(10);
	for(int i = 0; i < 10; i++) {
		l2[i] = i;
	}
	assert(l2[0] == 0);
	assert((l2.slice(1, 9, 1))[0] == 1);
	cout << "1 ";
	assert((l2.slice(5)).getSize() == 5);
	cout << "2 ";
	assert((l2.slice(8,9))[0] == 8);
	cout << "Passed!" << endl;




	cout << "All tests passed!" << endl;
	return 0;
}

//int main() {
//    cout << "Test constructors...\n";
//    CS112List lst;
//    assert(lst.getSize() == 0);
//
//    CS112List lst2(5);
//    assert(lst2.getSize() == 5);
//
//    cout << "Testing getValue\n";
//    assert(lst2.getValue(0) == "");
//    assert(lst2.getValue(4) == "");
//    try {
//        assert(lst2.getValue(5) == "");
//        assert(false);
//    } catch (const range_error &re) {
//        // do nothing here: All is well!
//    }
//
//    cout << "testing setValue\n";
//    lst2.setValue(0, "hi");
//    assert(lst2.getValue(0) == "hi");
//    try {
//        assert(lst2.getValue(5) == "");
//        assert(false);
//    } catch (const range_error &re) {
//        // do nothing here: All is well!
//    }
//
//    cout << "Testing []\n";
//    assert(lst2[0] == "hi");  // getting the value
//    lst2[1] = "hello";        // setting the value.
//    assert(lst2[1] == "hello");
//    try {
//        assert(lst2[5] == "");
//        assert(false);
//    } catch (const range_error &re) {
//        // do nothing here: All is well!
//    }
//
//    cout << "Test copy constructor\n";
//    CS112List lst3(lst2);
//    assert(lst3.getSize() == lst2.getSize());
//    lst2[2] = "please work!";
//    assert(lst3[2] != "please work!");
//
//    cout << "Testing printing...\n";
//    CS112List lst4(2);
//    lst4[0] = "Emma";
//    lst4[1] = "Wang";
//    cout << "This is a list -->" << lst4 << "<--\n";
//
//    cout << "Testing append...\n";
//    CS112List aList;
//    assert(aList.getSize() == 0);
//    aList.append("Alex");
//    assert(aList.getSize() == 1);
//    assert(aList[0] == "Alex");
//    cout << aList << endl;
//
//    aList.append("Heyab");
//    assert(aList.getSize() == 2);
//    assert(aList[0] == "Alex");
//    assert(aList[1] == "Heyab");
//    cout << aList << endl;
//
//    aList.append("Prof Norman is weird.");
//    cout << aList << endl;
//
//    cout << "Testing operator+" << endl;
//    CS112List l1;
//    l1.append("Hi");
//    CS112List l2;
//    l2.append("Nihao");
//	l2.append("Konnichiwa");
//    CS112List l3 = l1 + l2;
//    cout << l3 << endl;
//    assert(l3.getSize() == 3);
//    assert(l3[0] == "Hi");
//    assert(l3[1] == "Nihao");
//    assert(l3[2] == "Konnichiwa");
//
//     cout << "Testing negative indexes..." << endl;
//     assert(l3[-1] == "Konnichiwa");
//    assert(l3[-2] == "Nihao");
//     assert(l3.getValue(-2) == "Nihao");
//     try {
// 	l3[-4];
// 	assert(false);
//     } catch (const range_error &re) {
//     	// nothing here.
//     }
//     l3[-1] = "AufWiedersehen";
//     assert(l3[2] == "AufWiedersehen");
//     l3.setValue(-1, "Hallo");
//     assert(l3[2] == "Hallo");
//
//    cout << "All tests passed!\n";
//    return 0;
//}

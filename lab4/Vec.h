/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	//constructers and destructors
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	virtual ~Vec();
	
	//getters
	unsigned getSize() const;
	Item getItem(unsigned index) const;

	//setters
	void setItem(unsigned index, const Item& it);
	void setSize(unsigned newSize);

	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);

private:
	Item * myArray;
	unsigned mySize;
	friend class VecTester;
};

#endif /*VEC_H_*/

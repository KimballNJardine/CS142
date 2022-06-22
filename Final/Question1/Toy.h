#ifndef TOY_H
#define TOY_H

#include <string>

using namespace std;

class Toy {

private:
	string name;  // the toy name, e.g. firetruck
	int numInStock;    // how many of this toy is in stock
	
	static const int MAX_IN_STOCK = 20;
	    // maximum number of a toy that can be kept in stock
	
public:
	Toy(string toyName, int toysInStock);
   void SetNumInStock(int toyStock);
   void SetName(string newName);
   string ToString();
	// Accessors
	string GetName() const { return name; }	    // Do NOT change
	int GetNumInStock() const { return numInStock; } // Do NOT change
};

#endif // TOY_H
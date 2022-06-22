#include <iostream>
#include "Toy.h"

using namespace std;

int main() {
   Toy* truck = new Toy("Truck", 8);
   Toy* blocks = new Toy("Blocks", 19);
   cout << truck->ToString() << endl;
   cout << blocks->ToString() << endl;
   blocks->SetName("Blocks Plus");
   cout << blocks->ToString() << endl;
   cout << "How many more trucks would you like to stock?" << endl;
   int numMoreTrucks = 0;
   cin >> numMoreTrucks;
   truck->SetNumInStock(numMoreTrucks + truck->GetNumInStock());
   cout << truck->ToString() << endl;
   return 0;
}
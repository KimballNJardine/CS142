#include <iostream>
#include <vector>
using namespace std;
int main() {
   int numInts = 20;
   int min = 0;
   vector<int*> pointers;
   vector<int> values;
   for(int i = min; i < numInts; i++) {
      int j = i;
      values.push_back(j);
      pointers.push_back(&values.at(i));
   }
   for(int i = min; i < numInts; i++){
      cout << "value i = " << i << endl;
      cout << "(&pointers):\t" << &pointers.at(i) << endl;
      cout << "(pointers):\t" << pointers.at(i) << endl;
      cout << "(&values):\t" << &values.at(i) << endl;
      cout << "(*pointers):\t" << *pointers.at(i) << endl;
      cout << "(values):\t"  << values.at(i) << endl;
      cout << endl;
   }

   cout << endl;
   cout << "erasing index 0 from values..." << endl;
   values.erase(values.begin() + 0);
   cout << "pointer address of value at 0 (pointer): " << pointers.at(0) << endl;
   cout << "pointer address of pointer at 0 (&pointer): " << &pointers.at(0) << endl;
   cout << "pointer value at 0 (*pointer): " << *pointers.at(0) << endl;
   cout << endl << endl;

   cout << "Testing with int* p and int val..." << endl;
   int* p;
   int val = 10;
   p = &val;
   cout << "pointer p address of val (p): " << p << endl;
   cout << "pointer p value (*p): " << *p << endl;
   cout << "pointer p address (&p): " << &p << endl;
   cout << "val value (val): " << val << endl;
   cout << "val address (&val): " << &val << endl;
   return 0;
}

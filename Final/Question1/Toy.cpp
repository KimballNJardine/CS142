#include <string>
#include "Toy.h"

using namespace std;

// TO DO: add the needed implementations of the required methods
Toy::Toy(string toyName, int toysInStock) {
   if(toyName.size() > 0){
      name = toyName;
   }
   else{
      name = "unknown";
   }
   SetNumInStock(toysInStock);
}

void Toy::SetNumInStock(int toyStock) {
   if(toyStock > MAX_IN_STOCK){
      numInStock = MAX_IN_STOCK;
   }
   else if(toyStock >= 0){
      numInStock = toyStock;
   }
   else if(toyStock <= -1){
      numInStock = 1;
   }
}

void Toy::SetName(string newName) {
   if(newName.size() > 0){
      name = newName;
   }
   return;
}

string Toy::ToString() {
   return to_string(numInStock) + " " + name + " in stock";
}

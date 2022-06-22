#include <iostream>
#include "ItemToPurchase.h"
#include <iomanip>

using namespace std;

void InitializeItem(ItemToPurchase& item, int index);
double ReturnPrice(ItemToPurchase item);

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;
    cout << fixed << setprecision(2);

    InitializeItem(item1, 1);
    string tempString = "";
    getline(cin, tempString);
    InitializeItem(item2, 2);

    cout << "TOTAL COST" << endl;
    double price = ReturnPrice(item1);
    price += ReturnPrice(item2);
    cout << endl << "Total: $" << price << endl;
    return 0;
}
void InitializeItem(ItemToPurchase& item, int index){
    cout << "Item " << index << endl;
    cout << "Enter the item name:";
    string name = "";
    getline(cin, name);
    item.SetName(name);
    cout  << "Enter the item price:";
    double price = 0.0;
    cin >> price;
    item.SetPrice(price);
    cout << "Enter the item quantity:";
    int quantity = 0;
    cin >> quantity;
    item.SetQuantity(quantity);
    cin.clear();
    cout << endl;

}
double ReturnPrice(ItemToPurchase item){
    double totalPrice = item.GetPrice() * item.GetQuantity();
    cout << item.GetName() << " " << item.GetQuantity() << " @ $"
        << item.GetPrice() << " = $" << totalPrice << endl;
    return totalPrice;
}

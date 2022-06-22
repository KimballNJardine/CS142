//
// Created by Kimball on 3/5/2022.
//
#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_DECIMAL_PLACES = 2;
ItemToPurchase::ItemToPurchase(): itemQuantity(0), itemPrice(0.0), itemName("none"), itemDescription("none") {}
ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}
void ItemToPurchase::SetName(string newName) {
    itemName = newName;
}
string ItemToPurchase::GetName() {
    return itemName;
}
void ItemToPurchase::SetPrice(double newPrice) {
    itemPrice = newPrice;
}
double ItemToPurchase::GetPrice() {
    return itemPrice;
}
void ItemToPurchase::SetQuantity(int newQuantity) {
    itemQuantity = newQuantity;
}
int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}
void ItemToPurchase::SetDescription(string newDescription) {
    itemDescription = newDescription;
}
string ItemToPurchase::GetDescription() {
    return itemDescription;
}
double ItemToPurchase::GetTotalPrice() {
    return GetPrice() * GetQuantity();
}
void ItemToPurchase::PrintCost() {
    cout << fixed << setprecision(NUM_DECIMAL_PLACES);
    cout << GetName() << " " << GetQuantity() << " @ $"
         << GetPrice() << " = $" << GetTotalPrice() << endl;
}
void ItemToPurchase::PrintDescription() {
    cout << GetName() << ": " << GetDescription() << endl;
}




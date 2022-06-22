//
// Created by Kimball on 3/5/2022.
//
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(): itemQuantity(0), itemPrice(0.0), itemName("none") {
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







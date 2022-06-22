//
// Created by Kimball on 3/7/2022.
//
#include "ShoppingCart.h"
#include <iostream>

const int DOES_NOT_EXIST = -1;
ShoppingCart::ShoppingCart():customerName("none"), dateCreated("January 1, 1970") {}
ShoppingCart::ShoppingCart(std::string customer, std::string date) {
	customerName = customer;
	dateCreated = date;
}
std::string ShoppingCart::GetCustomerName() {
	return customerName;
}
std::string ShoppingCart::GetDateCreated() {
	return dateCreated;
}
void ShoppingCart::AddItemToCart(ItemToPurchase newItem) {
	int indexOfItem = FindItem(newItem.GetName());
	if(indexOfItem == DOES_NOT_EXIST) {
	   itemsSelected.push_back(newItem);
	}
	else {
	   cout << "Item is already found in the cart. It will not be added." << endl;
	}
}
void ShoppingCart::RemoveItemFromCart(std::string itemName) {
	int indexOfItem = FindItem(itemName);
	if(indexOfItem != DOES_NOT_EXIST){
		itemsSelected.erase(itemsSelected.cbegin() + indexOfItem);
	}
	else {
		cout << "Item not found in cart. It will not be removed." << endl;
	}
}
int ShoppingCart::FindItem(std::string itemName) { //Return index of item name. If item not found, return -1.
	for(long unsigned int i = 0; i < itemsSelected.size(); i++) {
		if(itemsSelected.at(i).GetName() == itemName) {
			return i;
		}
	}
	return DOES_NOT_EXIST;
}
void ShoppingCart::UpdateQuantityInCart(std::string itemName, int newQuantity) {
	int indexOfItem = FindItem(itemName);
	if(indexOfItem != DOES_NOT_EXIST) {
		itemsSelected.at(indexOfItem).SetQuantity(newQuantity);
	}
	else {
		cout << "Item not found in cart. It will not be modified." << endl;
	}
}
int ShoppingCart::NumItemsInCart() {
	int numItems = 0;
	for(long unsigned int i = 0; i < itemsSelected.size(); i++) {
		numItems += itemsSelected.at(i).GetQuantity();
	}
	return numItems;
}
double ShoppingCart::TotalCostOfItemsInCart() {
	double price = 0.00;
	for(long unsigned int i = 0; i < itemsSelected.size(); i++) {
		price += itemsSelected.at(i).GetTotalPrice();
	}
	return price;
}
void ShoppingCart::DescriptionOfItemsInCart() {
	PrintShoppingCart();
	if(itemsSelected.size() == 0){
		cout << "Shopping cart is empty." << endl;
		return;
	}
	cout << endl << "Item Descriptions" << endl;
	for(long unsigned int i = 0; i < itemsSelected.size(); i++) {
		itemsSelected.at(i).PrintDescription();
	}
	cout << endl;
}
void ShoppingCart::TotalNumPriceItemsInCart() {
	PrintShoppingCart();
	if(itemsSelected.size() == 0) {
		cout << "Shopping cart is empty." << endl;
		return;
	}
	else {
		double totalPrice = 0.00;
		cout << "Number of items: " << NumItemsInCart() << endl << endl;
		for(long unsigned int i = 0; i < itemsSelected.size(); i++) {
			itemsSelected.at(i).PrintCost();
			totalPrice += itemsSelected.at(i).GetTotalPrice();
		}
		cout << endl << "Total: $" << totalPrice << endl << endl;
	}
}
void ShoppingCart::PrintShoppingCart() {
	cout << GetCustomerName() << "'s Shopping Cart - " << GetDateCreated() << endl;
}


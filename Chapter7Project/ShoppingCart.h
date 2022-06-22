//
// Created by Kimball on 3/7/2022.
//

#ifndef CHAPTER7PROJECT_SHOPPINGCART_H
#define CHAPTER7PROJECT_SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"


class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(std::string customerName, std::string dateCreated);
        std::string GetCustomerName();
        std::string GetDateCreated();
        void AddItemToCart(ItemToPurchase newItem);
        void RemoveItemFromCart(std::string itemName);
        void UpdateQuantityInCart(std::string itemName, int newQuantity);
        int NumItemsInCart();
        double TotalCostOfItemsInCart();
        void DescriptionOfItemsInCart();
        void TotalNumPriceItemsInCart();
    private:
        std::string customerName;
        std::string dateCreated;
        vector<ItemToPurchase> itemsSelected;
        int FindItem(std::string itemName);
        void PrintShoppingCart();
};



#endif //CHAPTER7PROJECT_SHOPPINGCART_H

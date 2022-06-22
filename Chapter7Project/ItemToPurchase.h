//
// Created by Kimball on 3/5/2022.
//

#ifndef CHAPTER7PROJECT_ITEMTOPURCHASE_H
#define CHAPTER7PROJECT_ITEMTOPURCHASE_H

#include <string>
using namespace std;



class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string name, string description, double price, int quantity);
        void SetName(string newName);
        string GetName();
        void SetPrice(double newPrice);
        double GetPrice();
        void SetQuantity(int newQuantity);
        int GetQuantity();
        void SetDescription(string newDescription);
        string GetDescription();
        void PrintCost();
        void PrintDescription();
        double GetTotalPrice();

    private:
        string itemName;
        string itemDescription;
        double itemPrice;
        int itemQuantity;
};

#endif //CHAPTER7PROJECT_ITEMTOPURCHASE_H

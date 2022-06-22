//
// Created by Kimball on 3/5/2022.
//

#ifndef CHAPTER7LAB_ITEMTOPURCHASE_H
#define CHAPTER7LAB_ITEMTOPURCHASE_H

#include <string>
using namespace std;



class ItemToPurchase{
    public:
        ItemToPurchase();
        void SetName(string newName);
        string GetName();
        void SetPrice(double newPrice);
        double GetPrice();
        void SetQuantity(int newQuantity);
        int GetQuantity();

    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
};

#endif //CHAPTER7LAB_ITEMTOPURCHASE_H

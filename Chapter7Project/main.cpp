#include <iostream>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

std::string GetUserString(const std::string& prompt);
double GetUserDouble(const std::string& prompt);
int GetUserInt(const std::string& prompt);

int main() {
   std::string customerName = GetUserString("Enter Customer's Name: ");
   std::string todayDate = GetUserString("Enter Today's Date: ");

   ShoppingCart cart(customerName, todayDate);

   std::string userMenuChoice = "none";
   bool continueMenuLoop = true;
   while (continueMenuLoop) {
      userMenuChoice = GetUserString("Enter option: ");

      if (userMenuChoice == "add") {
         std::string itemName = GetUserString("Enter the item name: ");
         std::string itemDescription = GetUserString("Enter the item description: ");
         double itemPrice = GetUserDouble("Enter the item price: ");
         int itemQuantity = GetUserInt("Enter the item quantity: ");
         ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
         cart.AddItemToCart(newItem);
      }
      else if (userMenuChoice == "remove") {
         std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
         cart.RemoveItemFromCart(nameOfItemToRemove);
      }
      else if (userMenuChoice == "change") {
         std::string nameOfItemToChange = GetUserString("Enter the item name: ");
         int newItemQuantity = GetUserInt("Enter the new quantity: ");
         cart.UpdateQuantityInCart(nameOfItemToChange, newItemQuantity);
      }
      else if (userMenuChoice == "descriptions"){
         cart.DescriptionOfItemsInCart();
      }
      else if (userMenuChoice == "cart") {
         cart.TotalNumPriceItemsInCart();
      }
      else if (userMenuChoice == "options") {
         std::cout << "MENU" << std::endl
            << "add - Add item to cart" << std::endl
            << "remove - Remove item from cart" << std::endl
            << "change - Change item quantity" << std::endl
            << "descriptions - Print the items' descriptions" << std::endl
            << "cart - Print the shopping cart" << std::endl
            << "options - Print the options menu" << std::endl
            << "quit - Quit" << std::endl << std::endl;
      }
      else if (userMenuChoice == "quit") {
         std::cout << "Goodbye." << std::endl;
         continueMenuLoop = false;
      }
      else {
         std::cout << "MENU" << std::endl
            << "add - Add item to cart" << std::endl
            << "remove - Remove item from cart" << std::endl
            << "change - Change item quantity" << std::endl
            << "descriptions - Print the items' descriptions" << std::endl
            << "cart - Print the shopping cart" << std::endl
            << "options - Print the options menu" << std::endl
            << "quit - Quit" << std::endl << std::endl;
      }
   }

   return 0;
}


std::string GetUserString(const std::string& prompt) {
   std::string userAnswer = "none";

   std::cout << prompt;
   std::getline(std::cin, userAnswer);
   std::cout << std::endl;
   return userAnswer;
}
double GetUserDouble(const std::string& prompt) {
   double userAnswer = 0.0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}
int GetUserInt(const std::string& prompt) {
   int userAnswer = 0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}
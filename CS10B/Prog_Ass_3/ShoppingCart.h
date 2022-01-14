#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_

#include "ItemToPurchase.h"

#include <iostream>
#include <vector>

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(std::string name, std::string date);
    private:
        std::string _customerName;
        std::string _currentDate;
        std::vector<ItemToPurchase> _cartItems;
    public:
        std::string customerName() const;
        std::string date() const;
        void addItem(ItemToPurchase &i);
        void removeItem(std::string &itemName);
        void modifyItem(ItemToPurchase newItem);
        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal() const;
        void printDescriptions() const; 
};

#endif
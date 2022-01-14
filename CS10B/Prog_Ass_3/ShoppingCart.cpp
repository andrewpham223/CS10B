#include "ShoppingCart.h"

#include <iostream>
#include <vector>
using namespace std;

ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date) {
    _customerName = name;
    _currentDate = date;
}
string ShoppingCart::customerName() const { 
    return _customerName; 
}
string ShoppingCart::date() const { 
    return _currentDate; 
}
void ShoppingCart::addItem(ItemToPurchase &i) {
    _cartItems.push_back(i);
}
void ShoppingCart::removeItem(string &itemName) {
    bool b = false;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        if(_cartItems.at(i).name() == itemName) {
            b = true;
            _cartItems.erase(_cartItems.begin()+i);
        }
    }
    if(!b) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::modifyItem(ItemToPurchase newItem) {
    bool b = false;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        if(_cartItems.at(i).name() == newItem.name()) {
            b = true;
            _cartItems.at(i).setQuantity(newItem.quantity());
        }
    }
    if(!b) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}
int ShoppingCart::numItemsInCart() const {
    int count = 0;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        count += _cartItems.at(i).quantity();
    }
    return count;
}
int ShoppingCart::costOfCart() const {
    int count = 0;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        count += (_cartItems.at(i).quantity() * _cartItems.at(i).price());
    }
    return count;
}
void ShoppingCart::printTotal() const {
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << this->numItemsInCart() << endl << endl; 
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemCost();
    }
    if(_cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl << "Total: $" << this->costOfCart() << endl << endl;
}
void ShoppingCart::printDescriptions() const {
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl << "Item Descriptions" << endl;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemDescription();
    }
}
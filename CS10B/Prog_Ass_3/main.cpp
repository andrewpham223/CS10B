#include "ShoppingCart.h"

#include <iostream>
#include <vector>
using namespace std;

void printMenu(ShoppingCart &s);

int main() {
    string nameStr, dateStr;
    cout << "Enter customer's name: " << endl;
    getline(cin, nameStr);
    cout << "Enter today's date: " << endl;
    getline(cin, dateStr);
    cout << endl;
    cout << "Customer name: " << nameStr << endl;
    cout << "Today's date: " << dateStr << endl << endl;
    
    ShoppingCart s = ShoppingCart(nameStr, dateStr);
    printMenu(s);

    return 0;
}
void printMenu(ShoppingCart &s) {
    char inpChar = '1';
    while(inpChar != 'q') {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option: ";
        cin >> inpChar;
        cout << endl;

        while(inpChar != 'a' && inpChar != 'd' && inpChar != 'c' && inpChar != 'i' && inpChar != 'o' && inpChar != 'q') {
            cout << "Choose an option: ";
            cin >> inpChar;
            cout << endl;
        }
        if(inpChar == 'o') {
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            s.printTotal();
        }
        else if(inpChar == 'a') {
            cout << endl << "ADD ITEM TO CART" << endl;
            string tempName;
            string tempDesc;
            int tempPrice;
            int tempQuant;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, tempName);
            cout << "Enter the item description: " << endl;
            getline(cin, tempDesc);
            cout << "Enter the item price: " << endl;
            cin >> tempPrice;
            cout << "Enter the item quantity: " << endl;
            cin >> tempQuant;
            ItemToPurchase tempItem = ItemToPurchase(tempName, tempDesc, tempPrice, tempQuant);
            s.addItem(tempItem);
            cout << endl;
        }
        else if(inpChar == 'd') {
            string tempName;
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore();
            getline(cin, tempName);
            s.removeItem(tempName);
            cout << endl;
        }
        else if(inpChar == 'c') {
            string tempName;
            int newQuant;
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            ItemToPurchase tempItem = ItemToPurchase();
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, tempName);
            cout << "Enter the new quantity: " << endl;
            cin >> newQuant;
            tempItem.setName(tempName);
            tempItem.setQuantity(newQuant);
            s.modifyItem(tempItem);
            cout << endl;
        }
        else if(inpChar == 'i') {
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            s.printDescriptions();
            cout << endl;
        }
    }
        
}
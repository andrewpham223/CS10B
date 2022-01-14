#ifndef ITEMTOPURCHASE_H_
#define ITEMTOPURCHASE_H_

#include<iostream>
#include <vector>

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(std::string name, std::string description, int price, int quantity);
        std::string name() const;
        void setName(std::string &name);
        int price() const;
        void setPrice(int price);
        int quantity() const;
        void setQuantity(int quantity);
        std::string description() const;
        void setDescription(std::string description);
        void printItemCost() const;
        void printItemDescription() const;
    private:
        std::string _name;
        int _price;
        int _quantity;
        std::string _description;
};


#endif
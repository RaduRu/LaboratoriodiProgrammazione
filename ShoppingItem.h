//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H
#define LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H
#include <string>
#include "Subject.h"
using namespace std;

class ShoppingItem {
public:
    ShoppingItem(const string &name, const string &category): name(name), category(category){ }

     const string & getName() const {
        return name;
    }

    const string &getCategory() const {
        return category;
    }

    bool operator < (const ShoppingItem &item) const {
        return (name < item.getName() || (name == item.getName() && category < item.getCategory()));
    }

    bool operator == (const ShoppingItem &item) const {
        return (name == item.getName() && category == item.getCategory());
    }

    void setQuantity(int quantity) {
        if (quantity < 1) {
            throw std::invalid_argument("Quantity must be greater than 0");
        }
        this->quantity = quantity;
    }

    void addItem (){
        quantity++;
    }

    void setBought() {
        this->bought = !(this->bought);
    }

    bool isBought() const {
        return bought;
    }


private:
    string name;
    string category;
    int quantity = 1;
    bool bought = false;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H


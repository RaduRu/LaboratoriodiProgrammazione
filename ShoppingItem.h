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

     bool isEqual (const ShoppingItem &item) const {
        return (item.getName() == name && item.getCategory() == category);
    }

    bool operator < (const ShoppingItem &item) const {
        return (name < item.getName() || (name == item.getName() && category < item.getCategory()));
    }



private:
    string name;
    string category;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H

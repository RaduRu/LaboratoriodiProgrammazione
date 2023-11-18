//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H
#define LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H
#include <string>
#include <list>
using namespace std;
#include "Subject.h"

class ShoppingItem {
public:
    ShoppingItem(const string &name, const string &category): name(name), category(category){ }

     const string & getName() const {
        return name;
    }

    const string &getCategory(){
        return category;
    }

    bool operator==(const ShoppingItem &rhs) const {
        return name == rhs.name &&
               category == rhs.category;
    }


private:
    string name;
    string category;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H

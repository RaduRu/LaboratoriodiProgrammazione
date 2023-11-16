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
    ShoppingItem(const string &name, const string &category, int quantity): name(name), category(category), quantity(quantity) { }

    void setQuantity(int newQuantity){
        quantity= newQuantity;
    }
    const string &getName(){
        return name;
    }
    const string &getCategory(){
        return category;
    }
    int getQuantity(){
        return quantity;
    }


private:
    string name;
    string category;
    int quantity;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGITEM_H

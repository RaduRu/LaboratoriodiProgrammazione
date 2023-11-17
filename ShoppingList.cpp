//
// Created by Radu Ursu on 14/11/23.
//

#include "ShoppingList.h"
#include "ShoppingItem.h"
#include <iostream>
#include <map>
#include "Date.h"
using namespace std;


ShoppingList::ShoppingList(const string &name, int g, int m, int a ):date(g,m,a){
    this->name=name;
}

void ShoppingList :: addItem(const ShoppingItem &Newitem, int quantity){
    auto ExistingItem = Items.find(Newitem);
    if (ExistingItem != Items.end()){
        ExistingItem->second += quantity;
    }
    else{
        Items.insert(pair<ShoppingItem,int>(Newitem,quantity));
    }

    notify();
}

void ShoppingList :: removeItem(ShoppingItem item){
    auto ExistingItem = Items.find(item);
    if (ExistingItem != Items.end()){
        Items.erase(ExistingItem);
    }
    notify();
}










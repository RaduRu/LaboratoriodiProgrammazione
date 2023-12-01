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

const string &ShoppingList::getName() const {
    return name;
}

const map<ShoppingItem, int> &ShoppingList::getItems() const {
    return Items;
}

void ShoppingList :: addItem(const ShoppingItem &Newitem, int quantity){
    auto ExistingItem = std::find_if(Items.begin(), Items.end(), [&Newitem](const pair<ShoppingItem, int>& element) {
        return element.first.isEqual(Newitem);
    });
    if (ExistingItem != Items.end()){
        ExistingItem->second += quantity;
    }
    else{
        Items.insert(pair<ShoppingItem,int>(Newitem,quantity));
    }

    notify(this);
}

void ShoppingList :: removeItem(ShoppingItem item){
    auto ExistingItem = std::find_if(Items.begin(), Items.end(), [&item](const pair<ShoppingItem, int>& element) {
        return element.first.isEqual(item);
    });
    if (ExistingItem != Items.end()){
        Items.erase(ExistingItem);
    }
    notify(this);
}

void ShoppingList::subscribe(Observer *o) {
    ObserverList.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    ObserverList.remove(o);
}

void ShoppingList::notify(ShoppingList* updatedList) {
    for (auto observer : ObserverList) {
        observer->update();
    }
}










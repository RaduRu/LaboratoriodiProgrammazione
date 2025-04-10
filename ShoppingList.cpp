//
// Created by Radu Ursu on 14/11/23.
//

#include "ShoppingList.h"
#include "ShoppingItem.h"
#include <iostream>
#include <map>
using namespace std;


ShoppingList::ShoppingList(const string &name){
    this->name=name;
}

const string &ShoppingList::getName() const {
    return name;
}

void ShoppingList :: addItem(const ShoppingItem &Newitem){
    auto ExistingItem = std::find_if(Items.begin(), Items.end(), [&Newitem](const ShoppingItem & element) {
        return element == Newitem;
    });
    if (ExistingItem != Items.end()){
        ExistingItem->addOne();
    }
    else{
        Items.push_back(Newitem);
    }

    notify();
}

void ShoppingList :: removeItem(ShoppingItem item){
    auto ExistingItem = std::find_if(Items.begin(), Items.end(), [&item](const ShoppingItem & element) {
        return element == item;
    });
    if (ExistingItem != Items.end()){
        Items.erase(ExistingItem);
        notify();
    }
    else{
        cout << "Item not found in the list." << endl;
    }
}

void ShoppingList::subscribe(Observer *o) {
    ObserverList.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    ObserverList.remove(o);
}

void ShoppingList::notify() {
    for (auto observer : ObserverList) {
        observer->update(); // Notifica l'utente
    }
}










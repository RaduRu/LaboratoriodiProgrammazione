//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#define LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#include "Subject.h"
#include "ShoppingItem.h"
#include <vector>

class ShoppingList : public Subject {
public:
    //Here there's the function that adds an item to the ShoppingList
    void addItem(ShoppingItem &item);
    //Here there's the function that removes an item from the ShoppingList
    void removeItem(ShoppingItem &item);
    //We use this to look for an item in the ShoppingList
    const std::vector<ShoppingItem> &getItem();

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o)override;
    void notify() override;

private:
    list<ShoppingItem> Item;
    list<Observer*> ObserverList;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H

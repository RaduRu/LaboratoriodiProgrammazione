//
// Created by Radu Ursu on 14/11/23.
//

#include "ShoppingList.h"
#include "ShoppingItem.h"
#include <iostream>


void ShoppingList::addItem(ShoppingItem &item) {
    Item.push_back(item);
    notify();
}

void ShoppingList::removeItem(ShoppingItem &item) {
    Item.remove(item);
    notify();
}

//
// Created by Radu Ursu on 14/11/23.
//

#include "User.h"

User::User(const string &ID) : ID(ID) {
    this->ID = ID;
}

void User::addShoppingList(ShoppingList *shoppingList) {
    shoppingLists.push_back(shoppingList);
    shoppingList->subscribe(this);
}

void User::removeShoppingList(ShoppingList *shoppingList) {
    shoppingLists.remove(shoppingList);
    shoppingList->unsubscribe(this);
}

void User::addItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item, int quantity) {
    shoppingList->addItem(item,quantity);
}

void User::update() {

}




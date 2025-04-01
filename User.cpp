//
// Created by Radu Ursu on 14/11/23.
//

#include "User.h"
#include <iostream>
#include "ShoppingList.h"
#include "ShoppingItem.h"
using namespace std;

User::User(const string &ID) : ID(ID) {
    this->ID = ID;
}

void User::addShoppingList(ShoppingList *shoppingList) {
    shoppingLists.push_back(shoppingList);
    shoppingList->subscribe(this);
    lastShoppingListModified = shoppingList;
}

void User::removeShoppingList(ShoppingList *shoppingList) {
    shoppingLists.remove(shoppingList);
    shoppingList->unsubscribe(this);
    lastShoppingListModified = shoppingList;
}

void User::addItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item, int quantity) {
    lastShoppingListModified = shoppingList;
    shoppingList->addItem(item,quantity);

}

void User::removeItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item) {
    lastShoppingListModified = shoppingList;
    shoppingList->removeItem(item);

}



void User::update() {
cout << " L'utente " << ID << " è stato notificato che  " << lastShoppingListModified->getName() << " è stata cambiata " << endl;
    cout << " La nuova lista della spesa è la seguente: " << endl;
    for (auto item : lastShoppingListModified->getItems()) {
        cout << item.first.getName() << " q: " << item.second << endl;
    }
    cout << endl;

}




//
// Created by Radu Ursu on 14/11/23.
//

#include "User.h"
#include <iostream>
using namespace std;
#include "ShoppingList.h"
#include "ShoppingItem.h"

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



void User::update() {}
/*cout << " L'utente " << ID << " è stato notificato che  " << updatedList->getName() << " è stata cambiata " << endl;
    cout << " La nuova lista della spesa è la seguente: " << endl;
    for (auto item : updatedList->getItems()) {
        cout << item.first.getName() << " " << item.second << endl;
    }
    cout << endl;

}*/




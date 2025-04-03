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
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    lastShoppingListModified = shoppingList;
    shoppingList->addItem(item,quantity);

}

void User::removeItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    lastShoppingListModified = shoppingList;
    shoppingList->removeItem(item);

}

void User::printList(ShoppingList *list) {
    if(!verifyPermissionModList(list)) {
        return;
    }
    cout << "Lista della spesa: " << list->getName() << endl;
    const auto &items = list->getItems();
    for (const auto &pair: items) {
        cout << "- " << pair.first.getName()
             << " (" << pair.first.getCategory()
             << "): " << pair.second << " pezzi" << endl;
    }
}

bool User::verifyPermissionModList(ShoppingList *shoppingList) {
    auto Existingshoppinglist = std::find_if(shoppingLists.begin(), shoppingLists.end(), [&shoppingList](ShoppingList* list) {
        return list == shoppingList;
    });
    if (Existingshoppinglist == shoppingLists.end()) {
        cout << getID() << " non può accedere alla lista " << shoppingList->getName() << " perchè non partecipa più"  << endl;
        return false;
    }
    return true;
}



void User::update() {
cout << " L'utente " << ID << " è stato notificato che  " << lastShoppingListModified->getName() << " è stata cambiata " << endl;
    cout << " La nuova lista della spesa è la seguente: " << endl;
    printList(lastShoppingListModified);

}




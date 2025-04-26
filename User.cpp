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

void User::addItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    lastShoppingListModified = shoppingList;
    shoppingList->addItem(item);

}

void User::removeItemonShoppingList(ShoppingList *shoppingList, const ShoppingItem &item) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    lastShoppingListModified = shoppingList;
    shoppingList->removeItem(item);

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
    lastShoppingListModified->printList();

}

void User::searchItemsByName(ShoppingList *shoppingList, const string &name) {
    if (!verifyPermissionModList(shoppingList)) {
        return;
    }
    auto foundItems = shoppingList->ItemsByName(name);
    for (const auto& item : foundItems) {
        item.printItem();
    }
}


void User::searchItemsByCategory(ShoppingList *shoppingList, const string &category) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    list<ShoppingItem> foundItems = shoppingList->ItemsByCategory(category);
    for (const auto &item : foundItems) {
        item.printItem();
    }


}

void User::searchBoughtItems(ShoppingList *shoppingList) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    list<ShoppingItem> foundItems = shoppingList->ItemsBought();
    for (const auto &item : foundItems) {
        item.printItem();
    }

}

void User::searchUnboughtItems(ShoppingList *shoppingList) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    list<ShoppingItem> foundItems = shoppingList->ItemsNotBought();
    for (const auto &item : foundItems) {
        item.printItem();
    }

}

void User::buyItem(ShoppingList *shoppingList, const ShoppingItem &item) {
    if(!verifyPermissionModList(shoppingList)) {
        return;
    }
    lastShoppingListModified = shoppingList;
    shoppingList->setItemBought(item);

}




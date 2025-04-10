//
// Created by Radu Ursu on 14/11/23.
//

#include "ShoppingList.h"
#include "ShoppingItem.h"
#include <iostream>
#include <string>

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

void ShoppingList::PrintListsearch(list<ShoppingItem> list) {
    for (const auto &item : list) {
        item.printItem();
    }
}

void ShoppingList::printList() {
    cout << "Lista della spesa: " << name << endl;
    for (const auto &item : Items) {
        item.printItem();
    }

}

void ShoppingList::searchItemsByName(string name) {
    list<ShoppingItem> foundItems;
    for (const auto &item : Items) {
        if (item.getName().contains(name)) {
            foundItems.push_back(item);
        }
    }
    PrintListsearch(foundItems);

}

void ShoppingList::searchItemsByCategory(string category) {
    list<ShoppingItem> foundItems;
    for (const auto &item : Items) {
        if (item.getCategory()==category) {
            foundItems.push_back(item);
        }
    }
    PrintListsearch(foundItems);

}

void ShoppingList::searchItemsBought() {
    list<ShoppingItem> foundItems;
    for (const auto &item : Items) {
        if (item.isBought()) {
            foundItems.push_back(item);
        }
    }
    PrintListsearch(foundItems);

}

void ShoppingList::searchItemsNotBought() {
    list<ShoppingItem> foundItems;
    for (const auto &item : Items) {
        if (!item.isBought()) {
            foundItems.push_back(item);
        }
    }
    PrintListsearch(foundItems);

}

void ShoppingList::setItemBought(ShoppingItem item) {
    auto ExistingItem = std::find_if(Items.begin(), Items.end(), [&item](const ShoppingItem & element) {
        return element == item;
    });
    if (ExistingItem != Items.end()){
        ExistingItem->setBought();
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









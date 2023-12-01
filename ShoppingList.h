//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#define LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#include "Subject.h"
#include "ShoppingItem.h"
#include <list>
#include <map>
#include "Date.h"


class ShoppingList : public Subject {
public:
    ShoppingList(const string &name, int g, int m, int a);
    void addItem( const ShoppingItem& item, int quantity);
    void removeItem(ShoppingItem item);
    const string &getName() const;
    const map<ShoppingItem, int> &getItems() const;

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o)override;
    void notify() override;

private:
    Date date;
    string name;
    map<ShoppingItem,int> Items;
    list<Observer*> ObserverList;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H

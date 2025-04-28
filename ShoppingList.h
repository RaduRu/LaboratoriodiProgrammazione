//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#define LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H
#include "Subject.h"
#include "ShoppingItem.h"
#include <list>
#include <map>



class ShoppingList : public Subject {
public:
    explicit ShoppingList(const string &name);
    void addItem( const ShoppingItem& item);
    void removeItem(const ShoppingItem& item);
    const string &getName() const;
    list<ShoppingItem> ItemsByName(const string &nameItem);
    list<ShoppingItem>  ItemsByCategory(const string &category);
    list<ShoppingItem>  ItemsBought();
    list<ShoppingItem> ItemsNotBought();
    void setItemBought(ShoppingItem& item);
    void printList();

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o)override;
    void notify() override;

private:
    string name;
    list<ShoppingItem> Items;
    list<Observer*> ObserverList;
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H

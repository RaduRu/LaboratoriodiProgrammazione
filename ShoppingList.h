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
    ShoppingList(const string &name);
    void addItem( const ShoppingItem& item);
    void removeItem(ShoppingItem item);
    const string &getName() const;
    void searchItemsByName(string name);
    void searchItemsByCategory(string category);
    void searchItemsBought();
    void searchItemsNotBought();
    void setItemBought(ShoppingItem item);
    void printList();





    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o)override;
    void notify() override;

private:
    string name;
    list<ShoppingItem> Items;
    list<Observer*> ObserverList;
    void PrintListsearch(list<ShoppingItem> list);
};


#endif //LABORATORIODIPROGRAMMAZIONE_SHOPPINGLIST_H

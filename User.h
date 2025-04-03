//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_USER_H
#define LABORATORIODIPROGRAMMAZIONE_USER_H
#include <list>
#include "ShoppingList.h"
using namespace std;


class User : public Observer {


public:
    User(const string &ID);
    void addShoppingList(ShoppingList* shoppingList);
    void removeShoppingList(ShoppingList* shoppingList);
    void addItemonShoppingList(ShoppingList* shoppingList, const ShoppingItem& item, int quantity);
    void removeItemonShoppingList(ShoppingList* shoppingList, const ShoppingItem& item);
    void update() override;
    void printList(ShoppingList *list);
    bool verifyPermissionModList(ShoppingList *shoppingList);

    const string &getID() const {
        return ID;
    }
    ShoppingList* getLastShoppingListModified() const {
        return lastShoppingListModified;
    }




private:
    ShoppingList *lastShoppingListModified;
    string ID;
    list<ShoppingList*> shoppingLists;


};


#endif //LABORATORIODIPROGRAMMAZIONE_USER_H

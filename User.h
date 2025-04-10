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
    void addItemonShoppingList(ShoppingList* shoppingList, const ShoppingItem& item);
    void removeItemonShoppingList(ShoppingList* shoppingList, const ShoppingItem& item);
    bool verifyPermissionModList(ShoppingList *shoppingList);
    void searchItemsByName(ShoppingList *shoppingList, const string &name);
    void searchItemsByCategory(ShoppingList *shoppingList, const string &category);
    void searchBoughtItems(ShoppingList *shoppingList);
    void searchUnboughtItems(ShoppingList *shoppingList);
    void buyItem(ShoppingList *shoppingList, const ShoppingItem &item);



    void update() override;
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

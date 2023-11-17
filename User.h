//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_USER_H
#define LABORATORIODIPROGRAMMAZIONE_USER_H
#include <list>
#include "ShoppingList.h"


class User : public Observer {

public:
    User(const string &ID);
    void addShoppingList(ShoppingList* shoppingList);
    void removeShoppingList(ShoppingList* shoppingList);
    void addItemonShoppingList(ShoppingList* shoppingList, const ShoppingItem& item, int quantity);

    void update() override;



private:
    string ID;
    list<ShoppingList*> shoppingLists;


};


#endif //LABORATORIODIPROGRAMMAZIONE_USER_H

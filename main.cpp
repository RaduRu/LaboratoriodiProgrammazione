#include <iostream>
#include "ShoppingList.h"
#include "ShoppingItem.h"
#include "User.h"
using namespace std;

int main() {
    auto * list=new ShoppingList("Spesa Settimanale");

    ShoppingItem item1("Latte", "Alimenti");
    ShoppingItem item2("Pane", "Alimenti");
    ShoppingItem item3("Detersivo", "Pulizie");

    User user1("Marta");
    User user2("Luca");
    User user3("Pino");

    user1.addShoppingList(list);
    user1.addItemonShoppingList(list, item1);
    user2.addShoppingList(list);
    user2.addItemonShoppingList(list, item2);
    user2.addItemonShoppingList(list, item2);
    user2.removeItemonShoppingList(list, item2);

    user1.buyItem(list, item1);

    user2.removeShoppingList(list);
    user2.addItemonShoppingList(list, item3);

}
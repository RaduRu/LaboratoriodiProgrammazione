#include <iostream>
#include "ShoppingList.h"
#include "ShoppingItem.h"
#include "User.h"
using namespace std;

int main() {
    auto * list=new ShoppingList("Spesa Settimanale", 10, 11, 2023);

    ShoppingItem item1("Latte", "Alimenti");
    ShoppingItem item2("Pane", "Alimenti");
    ShoppingItem item3("Detersivo", "Pulizie");

    User user1("Marta");
    User user2("Luca");
    User user3("Pino");

    user1.addShoppingList(list);
    user1.addItemonShoppingList(list, item1, 2);
    user2.addShoppingList(list);
    user2.addItemonShoppingList(list, item2, 3);
    user2.removeItemonShoppingList(list, item2);

    user2.removeShoppingList(list);
    user2.addItemonShoppingList(list, item3, 1);
    user2.printList(list);
    user1.printList(list);

}
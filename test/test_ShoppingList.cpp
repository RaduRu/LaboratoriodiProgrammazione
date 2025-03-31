//
// Created by Radu Ursu on 31/03/25.
//

#include <gtest/gtest.h>
#include "../ShoppingList.h"
#include "../ShoppingItem.h"
#include <map>
#include <string>

using namespace std;

TEST(ShoppingListTest, ConstructorInitializesCorrectly) {
    ShoppingList list("My Shopping List", 31, 03, 2025);

    EXPECT_EQ(list.getName(), "My Shopping List");
    EXPECT_TRUE(list.getItems().empty());
}

TEST(ShoppingListTest, AddNewItemCorrectly) {
    ShoppingList list("My Shopping List", 31, 03, 2025);
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple, 3);
    ASSERT_EQ(list.getItems().size(), 1);
    EXPECT_EQ(list.getItems().at(apple), 3);
}

TEST(ShoppingListTest, RemoveItemCorrectly) {
    ShoppingList list("Test List", 31, 03, 2025);
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem bread("Bread", "Bakery");
    ShoppingItem coke("Coke", "Juice");
    // Caso 1: Rimuovere un elemento da una lista vuota
    list.removeItem(apple);
    EXPECT_TRUE(list.getItems().empty());
    list.addItem(apple, 3);
    list.addItem(bread, 2);
    list.addItem(coke, 1);

    // Caso 2: Rimuovere parzialmente un elemento con quantità > 1
    list.removeItem(apple);
    EXPECT_EQ(list.getItems().at(apple), 2);

    // Caso 3: Rimuovere completamente un elemento (quantità == 1)
    list.removeItem(bread);
    list.removeItem(bread);
    EXPECT_FALSE(list.getItems().count(bread));

    // Caso 4: Rimuovere un elemento non presente nella lista
    list.removeItem(bread);
    EXPECT_FALSE(list.getItems().count(bread));

    // Caso limite: Rimuovere dall'unico elemento rimasto
    list.removeItem(apple);
    list.removeItem(apple);
    list.removeItem(coke);
    EXPECT_TRUE(list.getItems().empty());
}
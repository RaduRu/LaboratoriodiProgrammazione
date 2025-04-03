//
// Created by Radu Ursu on 01/04/25.
//
#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h"
#include "../ShoppingItem.h"

TEST(UserTest, ConstructorInitializesCorrectly) {
    User user("Luca");
    EXPECT_EQ(user.getID(), "Luca");
}

TEST(UserTest, AddShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);

    user.addShoppingList(&shoppingList);
    shoppingList.notify();

    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica che il nome della lista notificata sia corretto
    EXPECT_TRUE(output.find("Lista1") != std::string::npos);
}

TEST(UserTest, RemoveShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);

    user.addShoppingList(&shoppingList);

    testing::internal::CaptureStdout();
    user.update();
    std::string outputBefore = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(outputBefore.find("Lista1") != std::string::npos);  // Verifica che "Lista1" sia presente

    // Rimuovo la lista
    user.removeShoppingList(&shoppingList);

    testing::internal::CaptureStdout();
    user.update();
    std::string outputAfter = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(outputAfter.find("Lista1") != std::string::npos);  // "Lista1" è l'ultima lista modificata
    EXPECT_TRUE(outputAfter.find("Lista2") == std::string::npos);  // verifico che non ci sia lista2

}

TEST(UserTest, AddItemOnShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);
    ShoppingItem item("Mela", "Frutta");
    int quantity = 3;


    user.addItemonShoppingList(&shoppingList, item, quantity);

    // Verifica: Controlla che lastShoppingListModified sia stato aggiornato correttamente
    EXPECT_EQ(&shoppingList, user.getLastShoppingListModified());

    // Verifica: Controlla che l'elemento sia effettivamente nella lista della spesa
    const auto& items = shoppingList.getItems();
    auto it = items.find(item);

    ASSERT_NE(it, items.end());
    EXPECT_EQ(it->second, quantity);
}

TEST(UserTest, RemoveItemFromShoppingList) {
    User user("Luca");
    ShoppingList list("Luca's List", 31, 03, 2025);
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem bread("Bread", "Bakery");


    user.addItemonShoppingList(&list, apple, 3);
    user.addItemonShoppingList(&list, bread, 1);

    EXPECT_EQ(list.getItems().at(apple), 3);
    EXPECT_EQ(list.getItems().at(bread), 1);

    // L'utente rimuove parzialmente un elemento
    user.removeItemonShoppingList(&list, apple);
    EXPECT_EQ(list.getItems().at(apple), 2);

    // L'utente rimuove completamente un elemento
    user.removeItemonShoppingList(&list, bread);
    EXPECT_FALSE(list.getItems().count(bread));

    // L'utente rimuove tutte le quantità rimanenti di un elemento fino a svuotare completamente la lista
    user.removeItemonShoppingList(&list, apple);
    user.removeItemonShoppingList(&list, apple);
    EXPECT_TRUE(list.getItems().empty());
}
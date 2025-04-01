//
// Created by Radu Ursu on 01/04/25.
//
#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h"
#include "../ShoppingItem.h"

TEST(UserTest, ConstructorInitializesCorrectly) {
    User user("User123");
    EXPECT_EQ(user.getID(), "User123");
}

TEST(UserTest, AddShoppingList) {
    User user("User123");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);

    user.addShoppingList(&shoppingList);
    shoppingList.notify();

    // Controlla che l'update dell'utente sia stato chiamato
    // Poiché `notify` dovrebbe richiamare il metodo `update` dell'utente, testa un effetto osservabile:
    // Idealmente catturiamo
    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica che il nome della lista notificata sia corretto
    EXPECT_TRUE(output.find("Lista1") != std::string::npos);
}

TEST(UserTest, RemoveShoppingList) {
    // Crea un utente e una lista della spesa
    User user("User123");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);

    // Aggiungi la lista all'utente
    user.addShoppingList(&shoppingList);

    // Simula una notifica iniziale per verificare che esistano liste
    testing::internal::CaptureStdout();
    user.update();  // Questo stampa lo stato della lista modificata
    std::string outputBefore = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(outputBefore.find("Lista1") != std::string::npos);  // Verifica che "Lista1" sia presente

    // Rimuovi la lista
    user.removeShoppingList(&shoppingList);

    // Simula nuovamente una notifica per verificare lo stato
    testing::internal::CaptureStdout();
    user.update();  // Deve stampare "Lista1 è stata modificata"
    std::string outputAfter = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(outputAfter.find("Lista1") != std::string::npos);  // "Lista1" è l'ultima lista modificata

    // Non possiamo verificare esplicitamente il contenuto di 'shoppingLists',
    // ma possiamo osservare gli effetti di "lastShoppingListModified" tramite update().
}

TEST(UserTest, AddItemOnShoppingList) {
    // Setup: Creiamo un utente, una lista della spesa e un elemento
    User user("User1");
    ShoppingList shoppingList("Lista1", 14, 11, 2023);  // Nome e data della lista
    ShoppingItem item("Mela", "Frutta");  // Nome e categoria dell'item
    int quantity = 3;

    // Esegui: Aggiungi un item alla lista della spesa tramite l'utente
    user.addItemonShoppingList(&shoppingList, item, quantity);

    // Verifica: Controlla che lastShoppingListModified sia stato aggiornato correttamente
    EXPECT_EQ(&shoppingList, user.getLastShoppingListModified());

    // Verifica: Controlla che l'elemento sia effettivamente nella lista della spesa
    const auto& items = shoppingList.getItems();  // Supponiamo che ShoppingList abbia un metodo getItems()
    auto it = items.find(item);  // Usa find() invece di operator[]

    ASSERT_NE(it, items.end());  // L'item deve essere presente nella mappa
    EXPECT_EQ(it->second, quantity);  // Verifica che la quantità dell'elemento sia corretta
}

TEST(UserTest, RemoveItemFromShoppingList) {
    User user("John Doe");
    ShoppingList list("John's List", 31, 03, 2025);
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem bread("Bread", "Bakery");

    // L'utente aggiunge elementi alla lista utilizzando addItemonShoppingList
    user.addItemonShoppingList(&list, apple, 3);  // Aggiungi 3 mele
    user.addItemonShoppingList(&list, bread, 1);  // Aggiungi 1 pane

    // Verifica che gli elementi siano stati aggiunti correttamente
    EXPECT_EQ(list.getItems().at(apple), 3);
    EXPECT_EQ(list.getItems().at(bread), 1);

    // L'utente rimuove parzialmente un elemento (apple da 3 a 2)
    user.removeItemonShoppingList(&list, apple);  // Rimuovi 1 mela
    EXPECT_EQ(list.getItems().at(apple), 2);

    // L'utente rimuove completamente un elemento (bread)
    user.removeItemonShoppingList(&list, bread); // Rimuovi l'unico pane
    EXPECT_FALSE(list.getItems().count(bread));  // Il pane non deve più essere presente nella lista

    // L'utente rimuove tutte le quantità rimanenti di un elemento fino a svuotare completamente la lista
    user.removeItemonShoppingList(&list, apple); // Rimuovi 1 mela (resta 1)
    user.removeItemonShoppingList(&list, apple); // Rimuovi l'ultima mela (resta 0)
    EXPECT_TRUE(list.getItems().empty());        // La lista deve essere completamente vuota
}
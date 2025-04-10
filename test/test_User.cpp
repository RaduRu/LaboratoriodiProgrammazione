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
    ShoppingList shoppingList("Lista1");

    user.addShoppingList(&shoppingList);
    shoppingList.notify();

    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica che il nome della lista notificata sia corretto
    EXPECT_TRUE(output.contains("Lista1") );
}

TEST(UserTest, RemoveShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingList shoppingList2("Lista2");

    user.addShoppingList(&shoppingList);
    user.removeShoppingList(&shoppingList);
    user.addShoppingList(&shoppingList2);


    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.contains("Lista1") );

}

TEST(UserTest, AddItemOnShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);


    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica che l'elemento sia stato aggiunto correttamente
    EXPECT_TRUE(output.contains("banana") );
}

TEST(UserTest, RemoveItemOnShoppingList) {
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);
    user.removeItemonShoppingList(&shoppingList, item);

    testing::internal::CaptureStdout();
    user.update();
    std::string output = testing::internal::GetCapturedStdout();

    // Verifica che l'elemento sia stato rimosso correttamente
    EXPECT_FALSE(output.contains("banana") );
}

TEST(UserTest, testsearchItemsByName){
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");
    ShoppingItem item2("apple", "Fruit");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);
    user.addItemonShoppingList(&shoppingList, item2);

    testing::internal::CaptureStdout();
    user.searchItemsByName(&shoppingList, "banana");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.contains("banana") );
    EXPECT_FALSE(output.contains("apple") );
}

TEST(UserTest, testsearchItemsByCategory){
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");
    ShoppingItem item2("apple", "Fruit");
    ShoppingItem item3("carrot", "Vegetable");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);
    user.addItemonShoppingList(&shoppingList, item2);
    user.addItemonShoppingList(&shoppingList, item3);

    testing::internal::CaptureStdout();
    user.searchItemsByCategory(&shoppingList, "Fruit");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.contains("banana") );
    EXPECT_TRUE(output.contains("apple") );
    EXPECT_FALSE(output.contains("carrot") );
}

TEST(UserTest, testSearchBoughtItems){
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");
    ShoppingItem item2("apple", "Fruit");
    ShoppingItem item3("carrot", "Vegetable");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);
    user.addItemonShoppingList(&shoppingList, item2);
    user.addItemonShoppingList(&shoppingList, item3);

    user.buyItem(&shoppingList, item);
    user.buyItem(&shoppingList, item2);

    testing::internal::CaptureStdout();
    user.searchBoughtItems(&shoppingList);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.contains("banana") );
    EXPECT_TRUE(output.contains("apple") );
    EXPECT_FALSE(output.contains("carrot") );
}

TEST(UserTest, testSearchUnBoughtItems){
    User user("Luca");
    ShoppingList shoppingList("Lista1");
    ShoppingItem item("banana", "Fruit");
    ShoppingItem item2("apple", "Fruit");
    ShoppingItem item3("carrot", "Vegetable");

    user.addShoppingList(&shoppingList);
    user.addItemonShoppingList(&shoppingList, item);
    user.addItemonShoppingList(&shoppingList, item2);
    user.addItemonShoppingList(&shoppingList, item3);

    user.buyItem(&shoppingList, item);
    user.buyItem(&shoppingList, item2);

    testing::internal::CaptureStdout();
    user.searchUnboughtItems(&shoppingList);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.contains("banana") );
    EXPECT_FALSE(output.contains("apple") );
    EXPECT_TRUE(output.contains("carrot") );
}










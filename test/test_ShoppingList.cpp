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
    ShoppingList list("My Shopping List");
    EXPECT_EQ(list.getName(), "My Shopping List");
}

TEST(ShoppingListTest, AddNewItemCorrectly) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple);

    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_TRUE(output.contains("Fruit"));
}

TEST(ShoppingListTest, AddExistingItemIncreasesQuantity) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple);
    list.addItem(apple);

    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_TRUE(output.contains("2"));
}

TEST(ShoppingListTest, RemoveItemCorrectly) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple);
    list.removeItem(apple);

    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.contains("Apple"));
}

TEST(ShoppingListTest, testItemsByName){
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem juice("Apple Juice", "Beverage");


    ShoppingItem banana("Banana", "Fruit");
    list.addItem(apple);
    list.addItem(banana);
    list.addItem(juice);

    testing::internal::CaptureStdout();
    list.ItemsByName("Apple");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_TRUE(output.contains("Apple Juice"));
    EXPECT_FALSE(output.contains("Banana"));

}

TEST(ShoppingListTest, testItemsByCategory){
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem juice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");
    list.addItem(apple);
    list.addItem(banana);
    list.addItem(juice);

    testing::internal::CaptureStdout();
    list.ItemsByCategory("Fruit");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_TRUE(output.contains("Banana"));
    EXPECT_FALSE(output.contains("Apple Juice"));

}

TEST(ShoppingListTest, testItemsBought){
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem juice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");
    list.addItem(apple);
    list.addItem(banana);
    list.addItem(juice);
    list.setItemBought(apple);
    list.setItemBought(banana);

    testing::internal::CaptureStdout();
    list.ItemsBought();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_TRUE(output.contains("Banana"));
    EXPECT_FALSE(output.contains("Apple Juice"));

}



TEST(ShoppingListTest, testItemsnotBought){
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem juice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");
    list.addItem(apple);
    list.addItem(banana);
    list.addItem(juice);
    list.setItemBought(banana);

    testing::internal::CaptureStdout();
    list.ItemsNotBought();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Apple"));
    EXPECT_FALSE(output.contains("Banana"));
    EXPECT_TRUE(output.contains("Apple Juice"));

}










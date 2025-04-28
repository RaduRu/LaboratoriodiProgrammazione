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

    //prova a rimuovere un elemento non esistente
    testing::internal::CaptureStdout();
    list.removeItem(apple);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains("Item not found in the list."));
}

TEST(ShoppingListTest, TestItemsByName) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem appleJuice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");

    list.addItem(apple);
    list.addItem(appleJuice);
    list.addItem(banana);


    std::list<ShoppingItem> foundItems = list.ItemsByName("Apple");
    EXPECT_EQ(foundItems.size(), 2);

    //controllo che siano proprio Apple e Apple Juice
    bool foundApple = false;
    bool foundAppleJuice = false;
    bool foundBanana = false;

    for (const auto& item : foundItems) {
        if (item.getName() == "Apple") {
            foundApple = true;
        } else if (item.getName() == "Apple Juice") {
            foundAppleJuice = true;
        }
    }
    EXPECT_TRUE(foundApple);
    EXPECT_TRUE(foundAppleJuice);

    for (const auto& item : foundItems) {
        if (item.getName() == "Banana") {
            foundBanana = true;
        }
    }

    EXPECT_FALSE(foundBanana);
}

TEST(ShoppingListTest, TestItemsByName_NoMatch) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple);

    std::list<ShoppingItem> foundItems = list.ItemsByName("Orange");
    EXPECT_TRUE(foundItems.empty());
}


TEST(ShoppingListTest, TestItemsByCategory) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem appleJuice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");

    list.addItem(apple);
    list.addItem(appleJuice);
    list.addItem(banana);

    std::list<ShoppingItem> foundItems = list.ItemsByCategory("Fruit");
    EXPECT_EQ(foundItems.size(), 2);

    bool foundApple = false;
    bool foundBanana = false;
    bool foundAppleJuice = false;

    for (const auto& item : foundItems) {
        if (item.getName() == "Apple") {
            foundApple = true;
        } else if (item.getName() == "Banana") {
            foundBanana = true;
        }
    }

    EXPECT_TRUE(foundApple);
    EXPECT_TRUE(foundBanana);
    EXPECT_FALSE(foundAppleJuice);
}

TEST(ShoppingListTest, TestItemsByCategory_NoMatch) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    list.addItem(apple);

    std::list<ShoppingItem> foundItems = list.ItemsByCategory("Vegetable");
    EXPECT_TRUE(foundItems.empty());
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

    std::list<ShoppingItem> boughtItems = list.ItemsBought();
    bool foundApple = false;
    bool foundBanana = false;
    bool foundAppleJuice = false;

    for (const auto& item : boughtItems) {
        if (item.getName() == "Apple") {
            foundApple = true;
        } else if (item.getName() == "Banana") {
            foundBanana = true;
        } else if (item.getName() == "Apple Juice") {
            foundAppleJuice = true;
        }
    }

    EXPECT_TRUE(foundApple);
    EXPECT_TRUE(foundBanana);
    EXPECT_FALSE(foundAppleJuice);
}

TEST(ShoppingListTest, TestItemsBoughtEmpty) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem banana("Banana", "Fruit");

    list.addItem(apple);
    list.addItem(banana);

    std::list<ShoppingItem> boughtItems = list.ItemsBought();
    EXPECT_TRUE(boughtItems.empty());
}

TEST(ShoppingListTest, testItemsNotBought) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem juice("Apple Juice", "Beverage");
    ShoppingItem banana("Banana", "Fruit");


    list.addItem(apple);
    list.addItem(banana);
    list.addItem(juice);
    list.setItemBought(apple);
    list.setItemBought(banana);
    std::list<ShoppingItem> notBoughtItems = list.ItemsNotBought();

    bool foundApple = false;
    bool foundBanana = false;
    bool foundAppleJuice = false;

    for (const auto& item : notBoughtItems) {
        if (item.getName() == "Apple") {
            foundApple = true;
        } else if (item.getName() == "Banana") {
            foundBanana = true;
        } else if (item.getName() == "Apple Juice") {
            foundAppleJuice = true;
        }
    }

    EXPECT_FALSE(foundApple);
    EXPECT_FALSE(foundBanana);
    EXPECT_TRUE(foundAppleJuice);
}

TEST(ShoppingListTest, TestItemsNotBoughtEmpty) {
    ShoppingList list("My Shopping List");
    ShoppingItem apple("Apple", "Fruit");
    ShoppingItem banana("Banana", "Fruit");

    list.addItem(apple);
    list.addItem(banana);
    list.setItemBought(apple);
    list.setItemBought(banana);

    std::list<ShoppingItem> notBoughtItems = list.ItemsNotBought();
    EXPECT_TRUE(notBoughtItems.empty());
}











//
// Created by Radu Ursu on 10/04/25.
//

#include <gtest/gtest.h>
#include "../ShoppingList.h"
#include "../ShoppingItem.h"
#include <map>
#include <string>


TEST(Shoppingitemtest, testConstructor) {
    ShoppingItem item("item1", "category1");
    EXPECT_EQ(item.getName(), "item1");
    EXPECT_EQ(item.getCategory(), "category1");
}

TEST(Shoppingitemtest, testaddOne) {
    ShoppingItem item("item1", "category1");
    item.setQuantity(5);
    item.addOne();
    EXPECT_EQ(item.getQuantity(), 6);
}


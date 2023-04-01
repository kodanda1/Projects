/**
 * @file ItemTest.cpp
 * @author your_name_here
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Aquarium.h>

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Aquarium *aquarium) : Item(aquarium) {}

};

TEST(ItemTest, Construct) {
    Aquarium aquarium;
    ItemMock item(&aquarium);
}
TEST(ItemTest, GettersSetters){
    Aquarium aquarium;
    ItemMock item(&aquarium);
    // Test initial values
    ASSERT_NEAR(0, item.GetX(), 0.0001);
    ASSERT_NEAR(0, item.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    item.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, item.GetX(), 0.0001);
    ASSERT_NEAR(17.2, item.GetY(), 0.0001);

    // Test a second with with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.0001);
    ASSERT_NEAR(-107, item.GetY(), 0.0001);
}


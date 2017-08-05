#include "../include/tree_node.h"
#include "gtest/gtest.h"

TEST(ConstructorTest, SetsInitKey) {
    tree_node<int> node(1);
    EXPECT_EQ(1, node.getKey());
}
#include "../include/avl_tree.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(insertNodeWithKeyTest, LeftLeftHeavyCase1) {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(0);
    stringstream ss;
    avlt.printTree(ss);
    string expectedOutput = 
        string("\t2\n") +
        string("1\n") +
        string("\t0\n");
    EXPECT_EQ(expectedOutput, ss.str());
}
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
    EXPECT_EQ(ss.str(), expectedOutput);
    auto node2 = avlt.getNodeWithKey(2);
    auto node1 = avlt.getNodeWithKey(1);
    auto node0 = avlt.getNodeWithKey(0);
    // test parents
    EXPECT_EQ(node2->getParent(), node1);
    EXPECT_EQ(node1->getParent(), nullptr);
    EXPECT_EQ(node0->getParent(), node1);
    // test heights
    EXPECT_EQ(node2->getHeight(), 0);
    EXPECT_EQ(node1->getHeight(), 1);
    EXPECT_EQ(node0->getHeight(), 0);
}

TEST(insertNodeWithKeyTest, LeftLeftHeavyCase2) {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(4);
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(5);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(3);
    avlt.insertNodeWithKey(0);
    stringstream ss;
    avlt.printTree(ss);
    string expectedOutput = 
        string("\t\t5\n") +
        string("\t4\n") +
        string("\t\t3\n") +
        string("2\n") +
        string("\t1\n") +
        string("\t\t0\n");
    EXPECT_EQ(ss.str(), expectedOutput);
    auto node5 = avlt.getNodeWithKey(5);
    auto node4 = avlt.getNodeWithKey(4);
    auto node3 = avlt.getNodeWithKey(3);
    auto node2 = avlt.getNodeWithKey(2);
    auto node1 = avlt.getNodeWithKey(1);
    auto node0 = avlt.getNodeWithKey(0);
    // test parents
    EXPECT_EQ(node5->getParent(), node4);
    EXPECT_EQ(node4->getParent(), node2);
    EXPECT_EQ(node3->getParent(), node4);
    EXPECT_EQ(node2->getParent(), nullptr);
    EXPECT_EQ(node1->getParent(), node2);
    EXPECT_EQ(node0->getParent(), node1);
    // test heights
    EXPECT_EQ(node5->getHeight(), 0);
    EXPECT_EQ(node4->getHeight(), 1);
    EXPECT_EQ(node3->getHeight(), 0);
    EXPECT_EQ(node2->getHeight(), 2);
    EXPECT_EQ(node1->getHeight(), 1);
    EXPECT_EQ(node0->getHeight(), 0);
}

TEST(insertNodeWithKeyTest, LeftRightHeavyCase1) {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(0);
    avlt.insertNodeWithKey(1);
    stringstream ss;
    avlt.printTree(ss);
    string expectedOutput = 
        string("\t2\n") +
        string("1\n") +
        string("\t0\n");
    EXPECT_EQ(ss.str(), expectedOutput);
    auto node2 = avlt.getNodeWithKey(2);
    auto node1 = avlt.getNodeWithKey(1);
    auto node0 = avlt.getNodeWithKey(0);
    // test parents
    EXPECT_EQ(node2->getParent(), node1);
    EXPECT_EQ(node1->getParent(), nullptr);
    EXPECT_EQ(node0->getParent(), node1);
    // test heights
    EXPECT_EQ(node2->getHeight(), 0);
    EXPECT_EQ(node1->getHeight(), 1);
    EXPECT_EQ(node0->getHeight(), 0);
}

TEST(insertNodeWithKeyTest, LeftRightHeavyCase2) {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(4);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(5);
    avlt.insertNodeWithKey(0);
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(3);
    stringstream ss;
    avlt.printTree(ss);
    string expectedOutput = 
        string("\t\t5\n") +
        string("\t4\n") +
        string("\t\t3\n") +
        string("2\n") +
        string("\t1\n") +
        string("\t\t0\n");
    EXPECT_EQ(ss.str(), expectedOutput);
    auto node5 = avlt.getNodeWithKey(5);
    auto node4 = avlt.getNodeWithKey(4);
    auto node3 = avlt.getNodeWithKey(3);
    auto node2 = avlt.getNodeWithKey(2);
    auto node1 = avlt.getNodeWithKey(1);
    auto node0 = avlt.getNodeWithKey(0);
    // test parents
    EXPECT_EQ(node5->getParent(), node4);
    EXPECT_EQ(node4->getParent(), node2);
    EXPECT_EQ(node3->getParent(), node4);
    EXPECT_EQ(node2->getParent(), nullptr);
    EXPECT_EQ(node1->getParent(), node2);
    EXPECT_EQ(node0->getParent(), node1);
    // test heights
    EXPECT_EQ(node5->getHeight(), 0);
    EXPECT_EQ(node4->getHeight(), 1);
    EXPECT_EQ(node3->getHeight(), 0);
    EXPECT_EQ(node2->getHeight(), 2);
    EXPECT_EQ(node1->getHeight(), 1);
    EXPECT_EQ(node0->getHeight(), 0);
}
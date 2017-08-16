/**
Unit tests for tree_node class.
Copyright (C) 2017  Daniel Gilbert (Daniel.Stephen.Gilbert@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gtest/gtest.h"
#include <sstream>
#include "../include/tree_node.h"

class TreeNodeTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            node3 = make_unique<tree_node<int>>(3);
            node1 = make_unique<tree_node<int>>(1);
            node5 = make_unique<tree_node<int>>(5);
            node0 = make_unique<tree_node<int>>(0);
            node2 = make_unique<tree_node<int>>(2);
            node4 = make_unique<tree_node<int>>(4);
            node6 = make_unique<tree_node<int>>(6);
            node0->setParent(node1.get());
            node2->setParent(node1.get());
            node1->setLeftChild(move(node0));
            node1->setRightChild(move(node2));
            node4->setParent(node5.get());
            node6->setParent(node5.get());
            node5->setLeftChild(move(node4));
            node5->setRightChild(move(node6));
            node1->setParent(node3.get());
            node5->setParent(node3.get());
            node3->setLeftChild(move(node1));
            node3->setRightChild(move(node5));
            node3->setParent(nullptr);
        }
        unique_ptr<tree_node<int>> node3;
        unique_ptr<tree_node<int>> node1;
        unique_ptr<tree_node<int>> node5;
        unique_ptr<tree_node<int>> node0;
        unique_ptr<tree_node<int>> node2;
        unique_ptr<tree_node<int>> node4;
        unique_ptr<tree_node<int>> node6;
};

TEST_F(TreeNodeTest, printTree) {
    stringstream ss;
    node3->printTree(ss);
    string expectedOutput = 
        string("\t\t6\n") +
        string("\t5\n") +
        string("\t\t4\n") +
        string("3\n") +
        string("\t\t2\n") +
        string("\t1\n") +
        string("\t\t0\n");
    EXPECT_EQ(ss.str(), expectedOutput);
}

TEST_F(TreeNodeTest, getNodeWithKey) {
    auto node = node3->getNodeWithKey(2);
    EXPECT_EQ(node->getKey(), 2);
}

TEST_F(TreeNodeTest, getMinimumNode) {
    auto node = node3->getMinimumNode();
    EXPECT_EQ(node->getKey(), 0);
}

TEST_F(TreeNodeTest, getSuccessorNodeAsChild) {
    auto node = node3->getSuccessorNode();
    EXPECT_EQ(node->getKey(), 4);
}

TEST_F(TreeNodeTest, getSuccessorNodeAsParent) {
    auto node = node3->getLeftChild()->getRightChild()->getSuccessorNode();
    EXPECT_EQ(node->getKey(), 3);
}
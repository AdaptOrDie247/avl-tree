/**
 * The driver program for the avl_tree class.
 * Author: Daniel Gilbert
 */

#include "include/avl_tree.h"
#include <iostream>
#include "include/tree_node.h"
using namespace std;

/**
 * Driver program for avl_tree class.
 * @return an int
 */
int main() {
//    // Test insertNode
//    avl_tree<int> avlt;
//    avlt.insertNodeWithKey(6);
//    avlt.insertNodeWithKey(4);
//    avlt.insertNodeWithKey(9);
//    avlt.insertNodeWithKey(1);
//    avlt.insertNodeWithKey(5);
//    avlt.insertNodeWithKey(8);
//    avlt.insertNodeWithKey(10);
//    avlt.insertNodeWithKey(0);
//    avlt.insertNodeWithKey(3);
//    avlt.insertNodeWithKey(7);
//    avlt.insertNodeWithKey(11);
//    avlt.insertNodeWithKey(2);
//    avlt.printTree();
//    // Test deleteNode with both children where successor is right child
//    avl_tree<int> avlt;
//    avlt.insertNodeWithKey(10);
//    avlt.insertNodeWithKey(6);
//    avlt.insertNodeWithKey(13);
//    avlt.insertNodeWithKey(4);
//    avlt.insertNodeWithKey(8);
//    avlt.insertNodeWithKey(12);
//    avlt.insertNodeWithKey(14);
//    avlt.insertNodeWithKey(2);
//    avlt.insertNodeWithKey(5);
//    avlt.insertNodeWithKey(7);
//    avlt.insertNodeWithKey(9);
//    avlt.insertNodeWithKey(11);
//    avlt.insertNodeWithKey(1);
//    avlt.insertNodeWithKey(3);
//    avlt.deleteNodeWithKey(13);
//    avlt.printTree();
    // Test deleteNode with both children where successor is not right child
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(13);
    avlt.insertNodeWithKey(5);
    avlt.insertNodeWithKey(18);
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(8);
    avlt.insertNodeWithKey(16);
    avlt.insertNodeWithKey(20);
    avlt.insertNodeWithKey(0);
    avlt.insertNodeWithKey(3);
    avlt.insertNodeWithKey(7);
    avlt.insertNodeWithKey(10);
    avlt.insertNodeWithKey(14);
    avlt.insertNodeWithKey(17);
    avlt.insertNodeWithKey(21);
    avlt.insertNodeWithKey(-1);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(4);
    avlt.insertNodeWithKey(6);
    avlt.insertNodeWithKey(11);
    avlt.insertNodeWithKey(15);
    avlt.insertNodeWithKey(-2);
    avlt.deleteNodeWithKey(13);
    avlt.printTree();
    return 0;
}
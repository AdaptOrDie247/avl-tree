/**
 * The driver program for the avl_tree class.
 * Author: Daniel Gilbert
 */

#include "avl_tree.h"
#include <iostream>
#include "tree_node.h"
using namespace std;

/**
 * Driver program for avl_tree class.
 * @return an int
 */
int main() {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(6);
    avlt.insertNodeWithKey(4);
    avlt.insertNodeWithKey(9);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(5);
    avlt.insertNodeWithKey(8);
    avlt.insertNodeWithKey(10);
    avlt.insertNodeWithKey(0);
    avlt.insertNodeWithKey(3);
    avlt.insertNodeWithKey(7);
    avlt.insertNodeWithKey(11);
    avlt.insertNodeWithKey(2);
    avlt.printTree();
    return 0;
}
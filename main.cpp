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
    avlt.insertNodeWithKey(2);
    avlt.insertNodeWithKey(1);
    avlt.insertNodeWithKey(0);
    avlt.printTree();
    return 0;
}
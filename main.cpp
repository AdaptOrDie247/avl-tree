/**
 * The driver program for the avl_tree class.
 * Author: Daniel Gilbert
 */

#include "avl_tree.h"
#include <iostream>
using namespace std;

/**
 * Driver program for avl_tree class.
 * @return an int
 */
int main() {
    avl_tree<int> avlt;
    avlt.insertNodeWithKey(10);
    avlt.insertNodeWithKey(5);
    avlt.insertNodeWithKey(15);
    avlt.insertNodeWithKey(12);
    avlt.insertNodeWithKey(13);
    avlt.printTree();
    avlt.deleteNodeWithKey(10);
    avlt.printTree();
    return 0;
}
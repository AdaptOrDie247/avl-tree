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
    avlt.insertNodeWithKey(10);
    cout << avlt.getNodeWithKey(10)->getHeight() << endl;
    avlt.insertNodeWithKey(5);
    cout << avlt.getNodeWithKey(10)->getHeight() << endl;
    avlt.insertNodeWithKey(4);
    cout << avlt.getNodeWithKey(10)->getHeight() << endl;
    avlt.insertNodeWithKey(1);
    cout << avlt.getNodeWithKey(10)->getHeight() << endl;
//    auto root = make_unique<tree_node<int>>(10);
//    root->setLeftChild(make_unique<tree_node<int>>(5));
//    root->setRightChild(make_unique<tree_node<int>>(15));
//    root->getRightChild()->setRightChild(make_unique<tree_node<int>>(20));
//    root->getRightChild()->setHeight(1);
//    cout << root->getBalanceFactor();
    return 0;
}
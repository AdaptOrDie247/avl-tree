/**
A program to demo the avl_tree class.
 */

#include "../include/avl_tree.h"
#include <iostream>

void insertNode(avl::avl_tree<int>&);
void deleteNode(avl::avl_tree<int>&);

/**
 * Demo program for avl_tree class using avl_tree<int>.
 * Author: Daniel Gilbert
 * @return an int
 */
int main() {
    avl::avl_tree<int> avlt;
    bool run = true;
    do {
        std::cout << "Demo program for avl_tree class using avl_tree<int>.\n"
                     "Author: Daniel Gilbert\n"
                     "1. Insert Node\n"
                     "2. Delete Node\n"
                     "3. Print Tree\n"
                     "4. Print Tree In Order\n"
                     "5. Print Tree Pre Order\n"
                     "6. Print Tree Post Order\n"
                     "7. Exit\n"
                     "Please make a selection, e.g. 1: ";
        int selection;
        std::cin >> selection;
        switch (selection) {
            case 1:
                insertNode(avlt);
                break;
            case 2:
                deleteNode(avlt);
                break;
            case 3:
                avlt.printTree(std::cout);
                break;
            case 4:
                avlt.printInOrder(std::cout); std::cout << std::endl;
                break;
            case 5:
                avlt.printPreOrder(std::cout); std::cout << std::endl;
                break;
            case 6:
                avlt.printPostOrder(std::cout); std::cout << std::endl;
                break;
            case 7:
                run = false;
                break;
        }
    } while (run);
    return 0;
}

void insertNode(avl::avl_tree<int>& avlt) {
    std::cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    std::cin >> key;
    avlt.insertNodeWithKey(key);
}

void deleteNode(avl::avl_tree<int>& avlt) {
    std::cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    std::cin >> key;
    avlt.deleteNodeWithKey(key);
}
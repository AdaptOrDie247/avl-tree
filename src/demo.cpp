#include "../include/avl_tree.h"
#include <iostream>
using namespace std;

void insertNode(avl_tree<int>&);
void deleteNode(avl_tree<int>&);

/**
 * Demo program for avl_tree class using avl_tree<int>.
 * Author: Daniel Gilbert
 * @return an int
 */
int main() {
    avl_tree<int> avlt;
    bool run = true;
    do {
        cout << "Demo program for avl_tree class using avl_tree<int>.\n"
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
        cin >> selection;
        switch (selection) {
            case 1:
                insertNode(avlt);
                break;
            case 2:
                deleteNode(avlt);
                break;
            case 3:
                avlt.printTree(cout);
                break;
            case 4:
                avlt.printInOrder(cout); cout << endl;
                break;
            case 5:
                avlt.printPreOrder(cout); cout << endl;
                break;
            case 6:
                avlt.printPostOrder(cout); cout << endl;
                break;
            case 7:
                run = false;
                break;
        }
    } while (run);
    return 0;
}

void insertNode(avl_tree<int>& avlt) {
    cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    cin >> key;
    avlt.insertNodeWithKey(key);
}

void deleteNode(avl_tree<int>& avlt) {
    cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    cin >> key;
    avlt.deleteNodeWithKey(key);
}
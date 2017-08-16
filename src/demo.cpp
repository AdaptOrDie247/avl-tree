/**
A program to demo the avl_tree class.
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

#include "../include/avl_tree.h"
#include <iostream>

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

void insertNode(avl_tree<int>& avlt) {
    std::cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    std::cin >> key;
    avlt.insertNodeWithKey(key);
}

void deleteNode(avl_tree<int>& avlt) {
    std::cout << "Please enter an int for the node's key, e.g. 1: ";
    int key;
    std::cin >> key;
    avlt.deleteNodeWithKey(key);
}
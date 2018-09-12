/**
AVL tree class.
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>
#include "tree_node.h"
#include <utility>

/**
 * An AVL tree class.
 * Author: Daniel Gilbert
 */
namespace avl {
template <class T>
class avl_tree {
    private:
        std::unique_ptr<tree_node<T>> root; /**< root. */
        
        /**
         * Replaces subtree rooted at rootToReplace with subtree rooted at
         * newRoot.
         * rootToReplace must be a tree node that exists in the tree.
         * @param rootToReplace the root of the subtree to replace
         * @param tempNewRoot the root of the subtree to replace with
         */
        void transplantSubTree(tree_node<T>* rootToReplace,
                               std::unique_ptr<tree_node<T>>& tempNewRoot);
        
        /**
         * Balance the subtree rooted at subRoot.
         * @param subRoot the root of the subtree to balance
         */
        void balance(tree_node<T>* subRoot);
        
        /**
         * Perform a right rotation around pivot.
         * @param pivot the pivot
         */
        void rotateRight(tree_node<T>* pivot);
        
        /**
         * Perform a left rotation around pivot.
         * @param pivot the pivot
         */
        void rotateLeft(tree_node<T>* pivot);
    public:
        
        /**
         * Prints the values of all the tree nodes in the tree in in-order.
         * Does nothing if there is no tree.
         * @param output output stream
         * @see printPreOrder()
         * @see printPostOrder()
         */
        void printInOrder(std::ostream& output) const {
            if (root) root->printTreeInOrder(output);
        }
        
        /**
         * Prints the values of all the tree nodes in the tree in pre-order.
         * Does nothing if there is no tree.
         * @param output output stream
         * @see printInOrder()
         * @see printPostOrder()
         */
        void printPreOrder(std::ostream& output) const {
            if (root) root->printTreePreOrder(output);
        }
        
        /**
         * Prints the values of all the tree nodes in the tree in post-order.
         * Does nothing if there is no tree.
         * @param output output stream
         * @see printInOrder()
         * @see printPreOrder()
         */
        void printPostOrder(std::ostream& output) const {
            if (root) root->printTreePostOrder(output);
        }
        
        /**
         * Calls root->printTree() if root exists.
         * @see printInOrder()
         * @see printPreOrder()
         * @see printPostOrder()
         */
        void printTree(std::ostream& output) {
            if (root) root->printTree(output);
        }
        
        /**
         * Inserts a tree node into the tree with key key.
         * @param key the key of the tree node to insert
         * @see deleteNodeWithKey()
         */
        void insertNodeWithKey(T key);
        
        /**
         * Calls root->getNodeWithKey(key).
         * Returns nullptr if the root tree node does not exist.
         * @param key the key to pass to root->getNodeWithKey(key)
         * @return return value from root->getNodeWithKey(key) or nullptr if
         * the root tree node does not exist
         * @see insertNodeWithKey()
         * @see deleteNodeWithKey()
         */
        tree_node<T>* getNodeWithKey(T key) {
            if (root) {
                root->getNodeWithKey(key);
            } else {
                return nullptr;
            }
        }
        
        /**
         * Deletes the first tree node found with key key.
         * Does nothing if a tree node with key key does not exist.
         * @param key the key of the tree node to delete
         * @see insertNodeWithKey()
         */
        void deleteNodeWithKey(T key);
};

template <class T>
void avl_tree<T>::transplantSubTree
    (tree_node<T>* rootToReplace, std::unique_ptr<tree_node<T>>& tempNewRoot) {
    auto newRoot = tempNewRoot.get();
    auto parentOfRootToReplace = rootToReplace->getParent();
    if (!parentOfRootToReplace) {
        root = move(tempNewRoot);
    } else if (rootToReplace ==
               parentOfRootToReplace->getLeftChild().get()) {
        parentOfRootToReplace->setLeftChild(move(tempNewRoot));
    } else {
        parentOfRootToReplace->setRightChild(move(tempNewRoot));
    }
    if (newRoot) newRoot->setParent(parentOfRootToReplace);
}

template <class T>
void avl_tree<T>::insertNodeWithKey(T key) {
    auto newNode = std::make_unique<tree_node<T>>(key);
    tree_node<T>* parentOfNewNode = nullptr;
    auto currentNode = root.get();
    while (currentNode) {
        parentOfNewNode = currentNode;
        if (key < currentNode->getKey()) {
            currentNode = currentNode->getLeftChild().get();
        } else {
            currentNode = currentNode->getRightChild().get();
        }
    }
    newNode->setParent(parentOfNewNode);
    // Get newNode raw pointer before newNode is moved
    currentNode = newNode.get();
    if (!parentOfNewNode) {
        root = move(newNode);
    } else if (key < parentOfNewNode->getKey()) {
        parentOfNewNode->setLeftChild(move(newNode));
    } else {
        parentOfNewNode->setRightChild(move(newNode));
    }
    // Update the heights and balance up to the root
    while (currentNode) {
        currentNode->setHeightFromChildren();
        if (currentNode->getBalanceFactor() < -1 ||
            currentNode->getBalanceFactor() > 1) {
            balance(currentNode);
        }
        currentNode = currentNode->getParent();
    }
}

template <class T>
void avl_tree<T>::balance(tree_node<T>* subRoot) {
    // Left heavy
    if (subRoot->getBalanceFactor() < -1) {
        // Left-right heavy
        if (subRoot->getLeftChild()->getBalanceFactor() > 0) {
            // Left rotation around child
            rotateLeft(subRoot->getLeftChild().get());
            // Right rotation around subroot
            rotateRight(subRoot);
        // Left heavy or left-left heavy
        } else {
            // Right rotation around subroot
            rotateRight(subRoot);
        }
    // Right heavy
    } else if (subRoot->getBalanceFactor() > 1) {
        // Right-left heavy
        if (subRoot->getRightChild()->getBalanceFactor() < 0) {
            // Right rotation around child
            rotateRight(subRoot->getRightChild().get());
            // Left rotation around subroot
            rotateLeft(subRoot);
        // Right heavy or right-right heavy
        } else {
            // Left rotation around subroot
            rotateLeft(subRoot);
        }
    }
}

template <class T>
void avl_tree<T>::rotateRight(tree_node<T>* pivot) {
    auto temp = move(pivot->getLeftChild());
    pivot->setLeftChild(move(temp->getRightChild()));
    if (pivot->getLeftChild()) pivot->getLeftChild()->setParent(pivot);
    pivot->setHeightFromChildren();
    // Get parent of pivot before pivot is moved
    auto parentOfPivot = pivot->getParent();
    // If the pivot is the root
    if (!parentOfPivot) {
        temp->setRightChild(move(root));
        temp->getRightChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        root = move(temp);
        root->setParent(nullptr);
    // If the pivot is the left child of its parent
    } else if (parentOfPivot->getLeftChild().get() == pivot) {
        temp->setRightChild(move(parentOfPivot->getLeftChild()));
        temp->getRightChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        parentOfPivot->setLeftChild(move(temp));
        parentOfPivot->getLeftChild()->setParent(parentOfPivot);
    // If the pivot is the right child of its parent
    } else {
        temp->setRightChild(move(parentOfPivot->getRightChild()));
        temp->getRightChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        parentOfPivot->setRightChild(move(temp));
        parentOfPivot->getRightChild()->setParent(parentOfPivot);
    }
}

template <class T>
void avl_tree<T>::rotateLeft(tree_node<T>* pivot) {
    auto temp = move(pivot->getRightChild());
    pivot->setRightChild(move(temp->getLeftChild()));
    if (pivot->getRightChild()) pivot->getRightChild()->setParent(pivot);
    pivot->setHeightFromChildren();
    // Get parent of pivot before pivot is moved
    auto parentOfPivot = pivot->getParent();
    // If the pivot is the root
    if (!parentOfPivot) {
        temp->setLeftChild(move(root));
        temp->getLeftChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        root = move(temp);
        root->setParent(nullptr);
    // If the pivot is the left child of its parent
    } else if (parentOfPivot->getLeftChild().get() == pivot) {
        temp->setLeftChild(move(parentOfPivot->getLeftChild()));
        temp->getLeftChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        parentOfPivot->setLeftChild(move(temp));
        parentOfPivot->getLeftChild()->setParent(parentOfPivot);
    // If the pivot is the right child of its parent
    } else {
        temp->setLeftChild(move(parentOfPivot->getRightChild()));
        temp->getLeftChild()->setParent(temp.get());
        temp->setHeightFromChildren();
        parentOfPivot->setRightChild(move(temp));
        parentOfPivot->getRightChild()->setParent(parentOfPivot);
    }
}

template <class T>
void avl_tree<T>::deleteNodeWithKey(T key) {
    auto node = getNodeWithKey(key);
    if (!node) return;
    // Get raw pointer to node's parent before node is replaced in transplant
    auto nodesParent = node->getParent();
    // If node has one child or no children
    if (!node->getLeftChild() || !node->getRightChild()) {
        // If node has no left child and possibly no right child
        if (!node->getLeftChild()) {
            transplantSubTree(node, node->getRightChild());
        // If node has a left child but no right child
        } else if (!node->getRightChild()) {
            transplantSubTree(node, node->getLeftChild());
        }
        // Update the heights and balance up to the root
        while (nodesParent) {
            nodesParent->setHeightFromChildren();
            if (nodesParent->getBalanceFactor() < -1 ||
                nodesParent->getBalanceFactor() > 1) {
                balance(nodesParent);
            }
            nodesParent = nodesParent->getParent();
        }
    // If node has both children
    } else {
        auto nodesSuccessor = node->getSuccessorNode();
        // Get nodesSuccessorsParent raw pointer before nodesSuccessor is
        // replaced by its right child being transplanted
        auto nodesSuccessorsParent = nodesSuccessor->getParent();
        // Create a new node to replace deleted node with
        auto tempNodesSuccessorAsReplacement =
            std::make_unique<tree_node<T>>(nodesSuccessor->getKey());
        // Get nodesSuccessorAsReplacement raw pointer before
        // tempNodesSuccessorAsReplacement is moved with transplant
        auto nodesSuccessorAsReplacement = 
            tempNodesSuccessorAsReplacement.get();
        // Needed for updating heights and rebalancing
        bool nodesSuccessorIsRightChild = true;
        // In case nodesSuccessor has no right child
        if (nodesSuccessorsParent != node) {
            nodesSuccessorIsRightChild = false;
            transplantSubTree(nodesSuccessor, nodesSuccessor->getRightChild());
            nodesSuccessorAsReplacement->
                setRightChild(move(node->getRightChild()));
            nodesSuccessorAsReplacement->getRightChild()->
                setParent(nodesSuccessorAsReplacement);
        } else {
            nodesSuccessorAsReplacement->
                setRightChild(move(nodesSuccessor->getRightChild()));
            if (nodesSuccessorAsReplacement->getRightChild()) {
                nodesSuccessorAsReplacement->getRightChild()->
                    setParent(nodesSuccessorAsReplacement);
            }
        }
        auto tempNodesLeftChild = move(node->getLeftChild());
        transplantSubTree(node, tempNodesSuccessorAsReplacement);
        nodesSuccessorAsReplacement->setLeftChild(move(tempNodesLeftChild));
        nodesSuccessorAsReplacement->getLeftChild()->
            setParent(nodesSuccessorAsReplacement);
        tree_node<T>* currentNode;
        if (nodesSuccessorIsRightChild) {
            currentNode = nodesSuccessorAsReplacement;
        } else {
            currentNode = nodesSuccessorsParent;
        }
        // Update the heights and balance up to the root
        while (currentNode) {
            currentNode->setHeightFromChildren();
            if (currentNode->getBalanceFactor() < -1 ||
                currentNode->getBalanceFactor() > 1) {
                balance(currentNode);
            }
            currentNode = currentNode->getParent();
        }
    }
}
}

#endif /* AVL_TREE_H */

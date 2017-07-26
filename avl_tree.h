
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <memory>
#include "tree_node.h"
#include <utility>
using namespace std;

/**
 * An AVL tree class.
 * Author: Daniel Gilbert
 */
template <class T>
class avl_tree {
    private:
        unique_ptr<tree_node<T>> root; /**< root. */
        
        /**
         * Replaces subtree rooted at rootToReplace with subtree rooted at
         * newRoot.
         * rootToReplace must be a tree node that exists in the tree.
         * @param rootToReplace the root of the subtree to replace
         * @param newRootUPR the root of the subtree to replace with
         */
        void transplantSubTree(tree_node<T>* rootToReplace,
                               unique_ptr<tree_node<T>>& newRootUPR);
    public:
        
        /**
         * Prints the values of all the tree nodes in the tree in in-order.
         * Does nothing if there is no tree.
         * @see printPreOrder()
         * @see printPostOrder()
         */
        void printInOrder() const { if (root) root->printTreeInOrder(); }
        
        /**
         * Prints the values of all the tree nodes in the tree in pre-order.
         * Does nothing if there is no tree.
         * @see printInOrder()
         * @see printPostOrder()
         */
        void printPreOrder() const { if (root) root->printTreePreOrder(); }
        
        /**
         * Prints the values of all the tree nodes in the tree in post-order.
         * Does nothing if there is no tree.
         * @see printInOrder()
         * @see printPreOrder()
         */
        void printPostOrder() const { if (root) root->printTreePostOrder(); }
        
        /**
         * Calls root->printTree() if root exists.
         * @see printInOrder()
         * @see printPreOrder()
         * @see printPostOrder()
         */
        void printTree() {
            if (root) root->printTree();
        }
        
        /**
         * Inserts a tree node into the tree with key key.
         * @param key the key of the tree node to insert
         * @see deleteNodeWithKey()
         */
        void insertNodeWithKey(T key);
        
        /**
         * Balance the subtree rooted at subRoot.
         * @param subRoot the root of the subtree to balance
         */
        void balance(tree_node<T>* subRoot);
        
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
    (tree_node<T>* rootToReplace, unique_ptr<tree_node<T>>& newRootUPR) {
    auto newRoot = newRootUPR.get();
    auto parentOfRootToReplace = rootToReplace->getParent();
    if (!rootToReplace->getParent()) {
        root = move(newRootUPR);
    } else if (rootToReplace ==
               parentOfRootToReplace->getLeftChild().get()) {
        parentOfRootToReplace->setLeftChild(move(newRootUPR));
    } else {
        parentOfRootToReplace->setRightChild(move(newRootUPR));
    }
    if (newRoot) newRoot->setParent(parentOfRootToReplace);
}

template <class T>
void avl_tree<T>::insertNodeWithKey(T key) {
    auto newNode = make_unique<tree_node<T>>(key);
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
    currentNode = newNode.get();
    if (!parentOfNewNode) {
        root = move(newNode);
    } else if (key < parentOfNewNode->getKey()) {
        parentOfNewNode->setLeftChild(move(newNode));
    } else {
        parentOfNewNode->setRightChild(move(newNode));
    }
    // Update the heights
    while (currentNode != root.get()
           && currentNode->getBalanceFactor() >= -1
           && currentNode->getBalanceFactor() <= 1) {
        currentNode->getParent()->setHeight(currentNode->getHeight() + 1);
        currentNode = currentNode->getParent();
    }
    balance(currentNode);
}

template <class T>
void avl_tree<T>::balance(tree_node<T>* subRoot) {
    if (subRoot->getBalanceFactor() < -1) {
        // left-left heavy
        if (subRoot->getLeftChild()->getBalanceFactor() < 0) {
            // right rotation around root
        // left-right heavy
        } else {
            // left rotation around child
            // right rotation around root
        }
    } else if (subRoot->getBalanceFactor() > 1) {
        // right-right heavy
        if (subRoot->getRightChild()->getBalanceFactor() > 0) {
            // left rotation around root
        // right-left heavy
        } else {
            // right rotation around child
            // left rotation around root
        }
    }
}

template <class T>
void avl_tree<T>::deleteNodeWithKey(T key) {
    auto node = getNodeWithKey(key);
    if (!node) return;
    if (!node->getLeftChild()) {
        transplantSubTree(node, node->getRightChild());
    } else if (!node->getRightChild()) {
        transplantSubTree(node, node->getLeftChild());
    } else {
        auto nodesSuccessor = node->getRightChild()->getMinimumNode();
        auto nodesSuccessorAsReplacementUP =
            make_unique<tree_node<T>>(nodesSuccessor->getKey());
        auto nodesSuccessorAsReplacement = nodesSuccessorAsReplacementUP.get();
        if (nodesSuccessor->getParent() != node) {
            transplantSubTree(nodesSuccessor, nodesSuccessor->getRightChild());
            nodesSuccessorAsReplacement->
                setRightChild(move(node->getRightChild()));
            nodesSuccessorAsReplacement->getRightChild()->
                setParent(nodesSuccessorAsReplacement);
        }
        auto nodesLeftChildUP = move(node->getLeftChild());
        transplantSubTree(node, nodesSuccessorAsReplacementUP);
        nodesSuccessorAsReplacement->setLeftChild(move(nodesLeftChildUP));
        nodesSuccessorAsReplacement->getLeftChild()->
            setParent(nodesSuccessorAsReplacement);
    }
}

#endif /* AVL_TREE_H */

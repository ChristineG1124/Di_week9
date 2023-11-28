//
// Created by Chang on 2023/11/27.
//
#include "BinaryTree.h"

BinaryTree::Node::Node(int aVal, BinaryTree::Node *left, BinaryTree::Node *right) {
    val = aVal;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if (aNodePtr == nullptr) {
        aNodePtr = aNewNodePtr;
    } else if (aNewNodePtr->val < aNodePtr->val) {
        insert(aNodePtr->left, aNewNodePtr);
    } else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinaryTree::insertNode(int aVal) {
    Node *newNode = new Node(aVal, nullptr, nullptr);
    insert(root, newNode);
}


void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    } else if (aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    } else{
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node *tempNodePtr = nullptr;
    if (aNodePtr == nullptr){
        cout << "Cannot delete empty node" << endl;
    } else if (aNodePtr->right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    } else if (aNodePtr->left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    } else {
        tempNodePtr = aNodePtr->right;

        while (tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;

        delete tempNodePtr;
    }
}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}


bool BinaryTree::searchNode(int aVal) {

    if (root == nullptr){
        return false;
    }
    else {
        Node *nodePtr = root;
        while (nodePtr != nullptr){
            if (aVal < nodePtr->val){
                nodePtr = nodePtr->left;
            } else if (aVal > nodePtr->val){
                nodePtr = nodePtr->right;
            }
            else{
                return true;
            }
        }
        return false;
    }
}


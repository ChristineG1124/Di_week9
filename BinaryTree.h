//
// Created by Chang on 2023/11/27.
//

#ifndef DI_9_BINARYTREE_H
#define DI_9_BINARYTREE_H

#include "iostream"

using namespace std;

class BinaryTree{
private:
    struct Node{
        int val;
        Node* left;
        Node* right;
        Node(int aVal, Node* left, Node* right);
    };

    Node* root;

    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinaryTree();

    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
};

#endif //DI_9_BINARYTREE_H

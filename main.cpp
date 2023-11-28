#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main() {
    BinaryTree tree;

    // Test insertion
    cout << "Inserting nodes..." << endl;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);

    // Test searching
    cout << "Searching for nodes..." << endl;
    cout << "Search for 5: " << (tree.searchNode(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 20: " << (tree.searchNode(20) ? "Found" : "Not Found") << endl;

    // Test deletion
    cout << "Deleting a node (5)..." << endl;
    tree.remove(5);
    cout << "Search for 5 after deletion: " << (tree.searchNode(5) ? "Found" : "Not Found") << endl;

    // Test deletion of a non-existing node
    cout << "Deleting a non-existing node (20)..." << endl;
    tree.remove(20);

    return 0;
}

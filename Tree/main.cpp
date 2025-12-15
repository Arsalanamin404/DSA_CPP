#include <iostream>
#include "BST.h" // Make sure you have your class definition here

using namespace std;

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder(); 
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(); 
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(); 
    cout << endl;

    // Search
    int key = 60;
    tree.search(key) ? cout << key << " found in BST." << endl : cout << key << " not found in BST." << endl;

    // Delete
    tree.del(70); // Node with two children
    cout << "Inorder after deleting 70: ";
    tree.inorder(); // Should show updated tree
    cout << endl;

    tree.del(30); // Node with one child
    cout << "Inorder after deleting 30: ";
    tree.inorder();
    cout << endl;

    tree.del(20); // Leaf node
    cout << "Inorder after deleting 20: ";
    tree.inorder();
    cout << endl;

    return 0;
}

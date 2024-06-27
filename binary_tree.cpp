//
// Created by Claudia Steiner on 27.06.24.
//
#include <iostream>
#include <stdexcept>

// Node structure representing each element in the binary tree
struct Node {
    int data;    // Data stored in the node
    Node* left;  // Pointer to the left child node
    Node* right; // Pointer to the right child node
};

// BinaryTree class using a binary tree
class BinaryTree {
private:
    Node* root;  // Pointer to the root of the tree

    // Helper function to insert a new value into the tree recursively
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            // Create a new node if the current node is null
            node = new Node();
            node->data = value;
            node->left = node->right = nullptr;
        } else if (value < node->data) {
            // Insert in the left subtree if the value is less than current node's data
            node->left = insert(node->left, value);
        } else {
            // Insert in the right subtree if the value is greater or equal to current node's data
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function to search for a value in the tree recursively
    bool search(Node* node, int value) const {
        if (node == nullptr) {
            return false;  // Value not found
        } else if (value == node->data) {
            return true;   // Value found
        } else if (value < node->data) {
            return search(node->left, value);  // Search in the left subtree
        } else {
            return search(node->right, value); // Search in the right subtree
        }
    }

    // Helper function to delete all nodes in the tree recursively
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    // Constructor initializes the tree to be empty
    BinaryTree() : root(nullptr) {}

    // Destructor to clean up the tree
    ~BinaryTree() {
        clear(root);  // Delete all nodes to free memory
    }

    // Inserts a new value into the tree
    void insert(int value) {
        try {
            root = insert(root, value);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            // Handle memory allocation failure if necessary
        }
    }

    // Searches for a value in the tree
    bool search(int value) const {
        return search(root, value);
    }

    // Checks if the tree is empty
    bool isEmpty() const {
        return root == nullptr;  // Tree is empty if root is nullptr
    }
};

// Main function to demonstrate the binary tree operations
int main() {
    BinaryTree tree;

    try {
        // Insert values into the tree
        tree.insert(10);
        tree.insert(20);
        tree.insert(5);

        // Search for values in the tree
        std::cout << "Search for 10: " << (tree.search(10) ? "Found" : "Not Found") << std::endl;
        std::cout << "Search for 15: " << (tree.search(15) ? "Found" : "Not Found") << std::endl;

        // Check if the tree is empty
        std::cout << "Is tree empty? " << (tree.isEmpty() ? "Yes" : "No") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

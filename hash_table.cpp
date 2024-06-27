//
// Created by Claudia Steiner on 27.06.24.
//
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Node structure representing a key-value pair in the hash table
struct HashNode {
    int key;
    std::string value;
    HashNode(int k, std::string v) : key(k), value(v) {}
};

// HashTable class using separate chaining for collision handling
class HashTable {
private:
    std::vector<std::list<HashNode>> table;  // Array of lists to handle collisions
    int tableSize;  // Size of the hash table

    // Hash function to calculate hash value for a key
    int hashFunction(int key) const {
        return key % tableSize;
    }

public:
    // Constructor initializes the hash table with a specified size
    HashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }

    // Inserts a key-value pair into the hash table
    void insert(int key, std::string value) {
        int hashValue = hashFunction(key);
        for (auto& node : table[hashValue]) {
            if (node.key == key) {
                node.value = value;  // Update the value if key already exists
                return;
            }
        }
        table[hashValue].emplace_back(key, value);  // Add new key-value pair
    }

    // Searches for a value based on the key
    std::string search(int key) const {
        int hashValue = hashFunction(key);
        for (const auto& node : table[hashValue]) {
            if (node.key == key) {
                return node.value;  // Key found, return the value
            }
        }
        throw std::out_of_range("Key not found");  // Edge case: Key not found
    }

    // Deletes a key-value pair from the hash table
    void remove(int key) {
        int hashValue = hashFunction(key);
        auto& nodes = table[hashValue];
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it->key == key) {
                nodes.erase(it);  // Key found, erase the node
                return;
            }
        }
        throw std::out_of_range("Key not found");  // Edge case: Key not found
    }

    // Checks if the hash table is empty
    bool isEmpty() const {
        for (const auto& nodes : table) {
            if (!nodes.empty()) {
                return false;
            }
        }
        return true;
    }
};

// Main function to demonstrate the hash table operations
int main() {
    HashTable hashTable(7);  // Initialize hash table with size 7 (a prime number)

    try {
        // Insert key-value pairs into the hash table
        hashTable.insert(1, "Alice");
        hashTable.insert(8, "Bob");
        hashTable.insert(15, "Charlie");

        // Search for values based on keys
        std::cout << "Search for key 1: " << hashTable.search(1) << std::endl;
        std::cout << "Search for key 8: " << hashTable.search(8) << std::endl;

        // Delete a key-value pair from the hash table
        hashTable.remove(8);
        std::cout << "Key 8 removed." << std::endl;

        // Attempt to search for a deleted key
        hashTable.search(8);  // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

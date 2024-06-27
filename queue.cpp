//
// Created by Claudia Steiner on 27.06.24.
//
#include <iostream>
#include <stdexcept>

// Node structure representing each element in the queue
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node
};

// In this snippet, we have implemented a Queue class using a linked list.
// The Queue class has the following member functions:
// Queue class using a linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor initializes the queue to be empty
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up the queue
    ~Queue() {
        // Dequeue all elements to free memory
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Enqueues an element at the rear of the queue
    void enqueue(int element) {
        try {
            Node* newNode = new Node();  // Create a new node
            newNode->data = element;     // Set the node's data
            newNode->next = nullptr;     // The new node will be the last node, so next is nullptr

            if (isEmpty()) {
                // If the queue is empty, both front and rear point to the new node
                front = rear = newNode;
            } else {
                // Link the new node to the end of the queue and update the rear pointer
                rear->next = newNode;
                rear = newNode;
            }
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            // Handle memory allocation failure if necessary
        }
    }

    // Dequeues the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            // Exception handling for empty queue
            throw std::out_of_range("Queue is empty. Cannot dequeue.");
        }
        Node* temp = front;  // Temporary pointer to the front node
        front = front->next; // Update the front to the next node
        delete temp;         // Delete the old front node to free memory

        // If the queue becomes empty after dequeuing, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Returns the front element without removing it
    int peek() const {
        if (isEmpty()) {
            // Exception handling for empty queue
            throw std::out_of_range("Queue is empty. Cannot peek.");
        }
        return front->data;  // Return the data of the front node
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return front == nullptr;  // Queue is empty if front is nullptr
    }
};

// Main function to demonstrate the queue operations
int main() {
    Queue queue;

    try {
        // Enqueue elements into the queue
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        // Display the front element
        std::cout << "Front element: " << queue.peek() << std::endl;

        // Dequeue an element from the queue
        queue.dequeue();
        std::cout << "Front element after dequeue: " << queue.peek() << std::endl;

        // Check if the queue is empty
        std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

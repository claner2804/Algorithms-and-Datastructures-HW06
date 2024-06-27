#include <iostream>
#include <stdexcept>

// Node structure representing each element in the stack
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node
};

// Stack class using a linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor initializes the stack to be empty
    Stack() : top(nullptr) {}

    // Destructor to clean up the stack
    ~Stack() {
        // Pop all elements to free memory
        while (!isEmpty()) {
            pop();
        }
    }

    // Pushes an element onto the top of the stack
    void push(int element) {
        try {
            Node* newNode = new Node();  // Create a new node
            newNode->data = element;     // Set the node's data
            newNode->next = top;         // Link the new node to the previous top
            top = newNode;               // Update the top to the new node
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            // Handle memory allocation failure if necessary
        }
    }

    // Pops the top element off the stack
    void pop() {
        if (isEmpty()) {
            // Exception handling for empty stack
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        Node* temp = top;  // Temporary pointer to the top node
        top = top->next;   // Update the top to the next node
        delete temp;       // Delete the old top node to free memory
    }

    // Returns the top element without removing it
    int peek() const {
        if (isEmpty()) {
            // Exception handling for empty stack
            throw std::out_of_range("Stack is empty. Cannot peek.");
        }
        return top->data;  // Return the data of the top node
    }

    // Checks if the stack is empty
    bool isEmpty() const {
        return top == nullptr;  // Stack is empty if top is nullptr
    }
};

// Main function to demonstrate the stack operations
int main() {
    Stack stack;

    try {
        // Push elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Display the top element
        std::cout << "Top element: " << stack.peek() << std::endl;

        // Pop an element from the stack
        stack.pop();
        std::cout << "Top element after pop: " << stack.peek() << std::endl;

        // Check if the stack is empty
        std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

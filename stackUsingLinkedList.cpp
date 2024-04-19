#include<iostream>
using namespace std;

// Define a structure for a node in the stack
struct stackNode {
  int data;           // Data of the node
  stackNode * next;   // Pointer to the next node
  stackNode(int d) {  // Constructor to initialize a node with data
    data = d;
    next = NULL;
  }
};

// Define the stack structure
struct stack {
  stackNode * top;    // Pointer to the top node of the stack
  int size;           // Variable to keep track of the size of the stack

  stack() {           // Constructor to initialize the stack
    top = NULL;       // Set the top pointer to NULL, indicating an empty stack
    size = 0;         // Initialize the size of the stack to 0
  }

  // Method to push an element onto the stack
  void stackPush(int x) {
    stackNode * element = new stackNode(x);  // Create a new node with the given data
    element->next = top;                      // Set the next pointer of the new node to the current top
    top = element;                            // Update the top pointer to the new node
    cout << "Element pushed" << "\n";         // Print a message indicating the element is pushed
    size++;                                   // Increment the size of the stack
  }

  // Method to pop an element from the stack
  int stackPop() {
    if (top == NULL) {                        // Check if the stack is empty
      return -1;                              // If empty, return -1 indicating underflow
    }
    int topData = top->data;                  // Store the data of the top node
    stackNode * temp = top;                   // Store the top node in a temporary pointer
    top = top->next;                          // Update the top pointer to the next node
    delete temp;                              // Delete the temporary node
    size--;                                   // Decrement the size of the stack
    return topData;                           // Return the data of the popped element
  }

  // Method to get the size of the stack
  int stackSize() {
    return size;                             // Return the size of the stack
  }

  // Method to check if the stack is empty
  bool stackIsEmpty() {
    return top == NULL;                      // Return true if the top pointer is NULL (indicating empty stack)
  }

  // Method to get the top element of the stack without removing it
  int stackPeek() {
    if (top == NULL) return -1;              // If stack is empty, return -1
    return top->data;                        // Return the data of the top node
  }

  // Method to print the elements of the stack
  void printStack() {
    stackNode * current = top;               // Start from the top node
    while (current != NULL) {                // Iterate until reaching the end of the stack
      cout << current->data << " ";          // Print the data of the current node
      current = current->next;               // Move to the next node
    }
  }
};

int main() {
  stack s;                                   // Create an instance of the stack

  s.stackPush(10);                           // Push an element onto the stack

  cout << "Element popped: " << s.stackPop() << "\n";  // Pop an element from the stack
  cout << "Stack size: " << s.stackSize() << "\n";     // Get the size of the stack
  cout << "Stack empty or not? " << s.stackIsEmpty() << "\n"; // Check if the stack is empty
  cout << "Stack's top element: " << s.stackPeek() << "\n";  // Get the top element of the stack
  return 0;
}
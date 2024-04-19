#include<bits/stdc++.h> // Includes all the standard C++ libraries
using namespace std;

class Stack {
  int size; // Variable to store the maximum size of the stack
  int * arr; // Pointer to dynamically allocate memory for the stack
  int top; // Variable to keep track of the top element's index
  public:
    Stack() { // Constructor to initialize the stack
      top = -1; // Initialize top to -1, indicating an empty stack
      size = 1000; // Set the default size of the stack to 1000
      arr = new int[size]; // Dynamically allocate memory for the stack
    }
  void push(int x) { // Method to push an element onto the stack
    top++; // Increment top to move to the next position
    arr[top] = x; // Assign the value to the top position in the stack
  }
  int pop() { // Method to pop an element from the stack
    int x = arr[top]; // Store the top element
    top--; // Decrement top to remove the top element
    return x; // Return the popped element
  }
  int Top() { // Method to get the top element of the stack
    return arr[top]; // Return the top element without removing it
  }
  int Size() { // Method to get the size of the stack
    return top + 1; // Return the number of elements in the stack
  }
};

int main() {
  Stack s; // Create an instance of the Stack class

  // Push elements onto the stack
  s.push(6);
  s.push(3);
  s.push(7);

  // Display the top element and size of the stack
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;

  // Pop an element from the stack
  cout << "The element deleted is " << s.pop() << endl;

  // Display the size of the stack and the top element after popping
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;

  return 0;
}

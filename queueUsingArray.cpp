#include<bits/stdc++.h> // Includes all the standard C++ libraries

using namespace std;

class Queue {
  int *arr;       // Pointer to the array to store elements
  int start, end; // Indices to track the start and end of the queue
  int currSize;   // Current size of the queue
  int maxSize;    // Maximum size of the queue

public:
  Queue() {                     // Default constructor
    arr = new int[16];          // Initialize array with a default size of 16
    start = -1;                 // Initialize start index to -1
    end = -1;                   // Initialize end index to -1
    currSize = 0;               // Initialize current size to 0
    maxSize = 16;               // Initialize maximum size to 16
  }

  Queue(int maxSize) {          // Constructor with custom maximum size
    this->maxSize = maxSize;    // Set maximum size
    arr = new int[maxSize];     // Allocate memory for the array
    start = -1;                 // Initialize start index to -1
    end = -1;                   // Initialize end index to -1
    currSize = 0;               // Initialize current size to 0
  }

  void push(int newElement) {   // Method to push an element into the queue
    if (currSize == maxSize) {  // Check if the queue is full
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) {            // If the queue is empty
      start = 0;                // Set start index to 0
      end = 0;                  // Set end index to 0
    } else                      // If the queue is not empty
      end = (end + 1) % maxSize; // Update end index with circular wrapping
    arr[end] = newElement;      // Insert new element at the end of the queue
    cout << "The element pushed is " << newElement << endl;
    currSize++;                 // Increment current size
  }

  int pop() {                   // Method to pop an element from the queue
    if (start == -1) {          // Check if the queue is empty
      cout << "Queue Empty\nExiting..." << endl;
      exit(1);
    }
    int popped = arr[start];    // Get the element at the start of the queue
    if (currSize == 1) {        // If there is only one element in the queue
      start = -1;               // Reset start index to -1
      end = -1;                 // Reset end index to -1
    } else                       // If there are more than one elements
      start = (start + 1) % maxSize; // Update start index with circular wrapping
    currSize--;                 // Decrement current size
    return popped;              // Return the popped element
  }

  int top() {                   // Method to get the element at the front of the queue
    if (start == -1) {          // Check if the queue is empty
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];          // Return the element at the start of the queue
  }

  int size() {                  // Method to get the current size of the queue
    return currSize;            // Return current size
  }
};

int main() {
  Queue q(6);                   // Create an instance of the Queue class with maximum size 6
  q.push(4);                    // Push elements into the queue
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl; // Print the front element of the queue
  cout << "The size of the queue before deletion " << q.size() << endl;            // Print the size of the queue
  cout << "The first element to be deleted " << q.pop() << endl;                    // Pop an element from the queue
  cout << "The peek of the queue after deleting an element " << q.top() << endl;    // Print the front element of the queue after deletion
  cout << "The size of the queue after deleting an element " << q.size() << endl;    // Print the size of the queue after deletion
  return 0;
}

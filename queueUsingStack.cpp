#include <bits/stdc++.h> // Includes all the standard C++ libraries

using namespace std;

class MyQueue {
public:
  stack<int> input, output; // Two stacks to simulate the queue

  MyQueue() {} // Constructor

  void push(int x) { // Method to push an element to the back of the queue
    cout << "The element pushed is " << x << endl;
    input.push(x); // Push the element onto the input stack
  }

  int pop() { // Method to remove and return the front element of the queue
    // If the output stack is empty, move elements from the input stack to the output stack
    if (output.empty())
      while (!input.empty())
        output.push(input.top()), input.pop();

    int x = output.top(); // Get the front element from the output stack
    output.pop(); // Remove the front element from the output stack
    return x; // Return the front element
  }

  int top() { // Method to get the front element of the queue without removing it
    // If the output stack is empty, move elements from the input stack to the output stack
    if (output.empty())
      while (!input.empty())
        output.push(input.top()), input.pop();
    return output.top(); // Return the front element from the output stack
  }

  int size() { // Method to get the size of the queue
    return (output.size() + input.size()); // Return the sum of the sizes of the two stacks
  }
};

int main() {
  MyQueue q; // Create an instance of the MyQueue class
  q.push(3); // Push elements into the queue
  q.push(4);
  cout << "The element popped is " << q.pop() << endl; // Pop an element from the queue
  q.push(5); // Push another element into the queue
  cout << "The top of the queue is " << q.top() << endl; // Get the front element of the queue
  cout << "The size of the queue is " << q.size() << endl; // Get the size of the queue
}

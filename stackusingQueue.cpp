#include<bits/stdc++.h> // Includes all the standard C++ libraries

using namespace std;

class Stack {
  queue<int> q; // Declare a queue to store elements
public:
  void Push(int x) {
    int s = q.size(); // Get the current size of the queue
    q.push(x); // Push the new element into the queue
    // Rearrange the queue elements to make the newly added element at the front
    for (int i = 0; i < s; i++) {
      q.push(q.front()); // Move the front element to the rear
      q.pop(); // Remove the front element
    }
  }

  int Pop() {
    int n = q.front(); // Get the front element of the queue (top element of the stack)
    q.pop(); // Remove the front element
    return n; // Return the popped element
  }

  int Top() {
    return q.front(); // Return the front element of the queue (top element of the stack)
  }

  int Size() {
    return q.size(); // Return the size of the queue (size of the stack)
  }
};

int main() {
  Stack s; // Create an instance of the Stack class

  // Push elements onto the stack
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);

  // Display the top element of the stack
  cout << "Top of the stack: " << s.Top() << endl;

  // Display the size of the stack before removing an element
  cout << "Size of the stack before removing element: " << s.Size() << endl;

  // Remove an element from the stack
  cout << "The deleted element is: " << s.Pop() << endl;

  // Display the top element of the stack after removing an element
  cout << "Top of the stack after removing element: " << s.Top() << endl;

  // Display the size of the stack after removing an element
  cout << "Size of the stack after removing element: " << s.Size();

  return 0;
}

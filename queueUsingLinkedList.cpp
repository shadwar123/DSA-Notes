#include<bits/stdc++.h> 
using namespace std;

// Define a class for a node in the queue
class QueueNode {
public:
    int val;         // Value of the node
    QueueNode *next; // Pointer to the next node

    QueueNode(int data) { // Constructor to initialize a node with data
        val = data;
        next = nullptr;
    }
};  

// Define global pointers to the front and rear of the queue
QueueNode *Front = nullptr, *Rare = nullptr;

// Define the Queue class
class Queue {
public:
    int size = 0; // Variable to store the size of the queue

    bool Empty();        // Method to check if the queue is empty
    void Enqueue(int value); // Method to enqueue (insert) an element into the queue
    void Dequeue();      // Method to dequeue (remove) an element from the queue
    int Peek();          // Method to get the front element of the queue without removing it
};  

bool Queue::Empty() { // Method to check if the queue is empty
    return Front == nullptr;
}  

int Queue::Peek() { // Method to get the front element of the queue without removing it
    if (Empty()) { // Check if the queue is empty
        cout << "Queue is Empty" << endl;
        return -1;
    } else {
        return Front->val; // Return the value of the front node
    }
}   

void Queue::Enqueue(int value) { // Method to enqueue (insert) an element into the queue
    QueueNode *Temp;
    Temp = new QueueNode(value); // Create a new node with the given value
    if (Temp == nullptr) { // Check if memory allocation failed
        cout << "Queue is Full" << endl;
    } else {
        if (Front == nullptr) { // If the queue is empty
            Front = Temp;       // Set both Front and Rare to the new node
            Rare = Temp;
        } else { // If the queue is not empty
            Rare->next = Temp; // Insert the new node at the rear of the queue
            Rare = Temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++; // Increment the size of the queue
    } 
}      

void Queue::Dequeue() { // Method to dequeue (remove) an element from the queue
    if (Front == nullptr) { // Check if the queue is empty
        cout << "Queue is Empty" << endl;
    } else {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front; // Store the front node in a temporary pointer
        Front = Front->next;     // Move Front to the next node
        delete Temp;             // Delete the front node
        size--;                 // Decrement the size of the queue
    }  
}   

int main() {
    Queue Q; // Create an instance of the Queue class

    // Enqueue elements into the queue
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);

    // Dequeue an element from the queue
    Q.Dequeue();

    // Print the size of the queue
    cout << "The size of the Queue is " << Q.size << endl;

    // Print the front element of the queue
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;

    return 0;
}   

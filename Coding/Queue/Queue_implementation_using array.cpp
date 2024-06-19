#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue() {
        size = 1001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) // Corrected the condition to check if rear has reached the maximum size
            cout << "Queue is full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        int ans = -1; // Initialize ans to -1 to handle the case when the queue is empty
        if (front == rear) {
            cout << "Queue is empty" << endl; // Added a message to indicate that the queue is empty
        } else {
            ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
                front = rear = 0;
        }
        return ans;
    }

    int getFront() {
        if (front == rear)
            return -1;
        else
            return arr[front];
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    cout << "Front element: " << q.getFront() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.getFront() << endl;
    
    if (q.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
    
    return 0;
}

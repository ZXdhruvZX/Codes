#include <iostream>

class Queue
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    bool isEmpty()
    {
        // Corrected the condition for checking if the queue is empty
        if ((front == -1 && rear == -1) || (rear == (front - 1 + size) % size))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool enqueue(int value)
    {
        // Corrected the condition for checking if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 ) % size))
        {
            return false;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front++;
                rear++;
                arr[rear] = value;
            }
            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
                arr[rear] = value;
            }
            else
            {
                arr[rear] = value;
                rear = (rear + 1) % size;
            }
            return true;
        }
    }

    bool dequeue()
    {
        if (front == -1 && rear == -1)
        {
            std::cout << "Queue is empty" << std::endl;
            return false; // Return false to indicate the dequeue operation failed
        }
        else
        {
            arr[front] = -1;
            if (front == rear)
            {
                // If there is only one element in the queue, reset front and rear
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            return true; // Return true to indicate successful dequeue
        }
    }
};

int main()
{
    Queue myQueue;

    // Enqueue some elements
    for (int i = 1; i <= 5; ++i)
    {
        if (myQueue.enqueue(i))
        {
            std::cout << "Enqueued: " << i << std::endl;
        }
        else
        {
            std::cout << "Queue is full. Enqueue operation failed." << std::endl;
        }
    }

    // Dequeue some elements
    for (int i = 1; i <= 3; ++i)
    {
        if (myQueue.dequeue())
        {
            std::cout << "Dequeued" << std::endl;
        }
        else
        {
            std::cout << "Queue is empty. Dequeue operation failed." << std::endl;
        }
    }

    // Enqueue more elements to test circular behavior
    for (int i = 6; i <= 8; ++i)
    {
        if (myQueue.enqueue(i))
        {
            std::cout << "Enqueued: " << i << std::endl;
        }
        else
        {
            std::cout << "Queue is full. Enqueue operation failed." << std::endl;
        }
    }

    return 0;
}

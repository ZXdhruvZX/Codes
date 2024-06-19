#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void insert_at_tail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        // If the list is empty, set both head and tail to the new node
        tail = temp;
    }
    else
    {
        // Otherwise, add the new node to the end of the list
        tail->next = temp;
        tail = temp;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // Creating a node
    Node *node1 = new Node(10);

    // Creating a head
    Node *head = node1;

    // Creating a tail
    Node *tail = node1;

    // Printing
    print(head);

    // Inserting values in tail
    insert_at_tail(tail, 12);
    // Printing
    cout << endl;
    print(head);

    // Inserting values at tail
    insert_at_tail(tail, 15);

    // Printing
    cout << endl;
    print(head);

    return 0;
}

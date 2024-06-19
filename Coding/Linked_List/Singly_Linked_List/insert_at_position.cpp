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

// Function prototype for insert_at_tail
void insert_at_tail(Node *&tail, int d);

void insert_at_position(Node *tail, Node *head, int pos, int d)
{
    int cnt = 1;
    Node *temp = head;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insert_at_tail(tail, d);
        return;
    }

    Node *newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}

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
    cout << endl;

    // Inserting Value at a particular position
    int pos;
    cout << "Enter the position you wanted to be entered:" << endl;
    cin >> pos;
    insert_at_position(tail, head, pos, 33);

    // Printing
    cout << endl;
    print(head);

    return 0;
}

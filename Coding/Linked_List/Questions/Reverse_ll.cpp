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

int main()
{
    int n;
    cout << "Enter how long you want your linked list to be" << endl;
    cin >> n;
    cout << "Enter the elements of the linked list" << endl;
    int d;
    Node *tail = NULL;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        Node *temp = new Node(d);
        if (tail == NULL)
        {
            tail = temp;
        }
        if (head == NULL)
            head = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "So the linked list is" << endl;
    Node *curr = head;
    for (int i = 0; i < n; i++)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;


    Node *prev = NULL;
    Node *current = head;
    Node *forward;

    // Reversing the Linked List
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    Node *turn;
    turn = head;
    head = tail;
    tail = turn;

    cout << "So the reversed linked list is" << endl;
    Node *currr = head;
    for (int i = 0; i < n; i++)
    {
        cout << currr->data << " ";
        currr = currr->next;
    }
}
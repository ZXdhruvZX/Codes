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
        this->next = NULL; // Initialize next pointer to NULL
    }
};

void insert_at_list1(Node *head1, int element)
{
    Node *temp = head1; // Use temp instead of temp1
    Node *data = new Node(element); // Create a new Node with the given element
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = data;
}

void insert_at_list2(Node *head2, int element)
{
    Node *temp = head2; // Use temp instead of temp1
    Node *data = new Node(element); // Create a new Node with the given element
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = data;
}

Node *compare(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    if (temp1)
    {
        temp->next = temp1;
    }
    else if (temp2)
    {
        temp->next = temp2; // Fixed the assignment operator here
    }

    return dummy->next;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl; // Print NULL at the end
}

int main()
{
    int x, y;
    cin >> x;
    Node *head1 = NULL; // Initialize head1 and head2 to NULL
    Node *head2 = NULL;

    for (int i = 0; i < x; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            Node *node1 = new Node(element);
            head1 = node1;
        }
        else
            insert_at_list1(head1, element);
    }

    cin >> y;
    for (int i = 0; i < y; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            Node *node1 = new Node(element);
            head2 = node1;
        }
        else
            insert_at_list2(head2, element);
    }

    Node *headd = compare(head1, head2);
    print(headd);

    return 0;
}

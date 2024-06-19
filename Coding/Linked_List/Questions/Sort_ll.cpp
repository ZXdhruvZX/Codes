#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *Sort_zero_ones_twos(Node *&head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            zerocount++;
        else if (temp->data == 1)
            onecount++;
        else
            twocount++;

        temp = temp->next; // Move to the next node
    }

    temp = head; // Reset temp to the head

    // Update nodes for each count of 0, 1, and 2
    for (int i = 0; i < zerocount; i++)
    {
        temp->data = 0;
        temp = temp->next;
    }

    for (int i = 0; i < onecount; i++)
    {
        temp->data = 1;
        temp = temp->next;
    }

    for (int i = 0; i < twocount; i++)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

void print(Node *head) // Fix function name
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *node2 = new Node(0);
    node1->next = node2;
    Node *node3 = new Node(0);
    node2->next = node3;
    Node *node4 = new Node(1);
    node3->next = node4;
    Node *node5 = new Node(2);
    node4->next = node5;

    print(head);
    Sort_zero_ones_twos(head);
    print(head);

    return 0;
}

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

bool palindrome(Node *head)
{
    int arr[4];
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    int a = 0;
    int b = i - 1; // Corrected the array index
    while (a < b)
    {
        if (arr[a] != arr[b])
            return false;
        a++;
        b--;
    }
    return true;
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
    cout << palindrome(head);

    // Free allocated memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

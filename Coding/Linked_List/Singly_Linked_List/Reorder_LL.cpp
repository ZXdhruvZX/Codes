#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertion(Node *head, int element)
{
    Node *node1 = new Node(element);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node1;
}

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverse(Node *mid)
{
    Node *prev = mid;
    Node *curr = mid->next;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    mid->next = NULL; // Set mid's next to NULL to break the list into two parts
    return prev; // Return the new head of the reversed list
}

void print(Node *head)
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
    int size;
    cin >> size;
    Node *head = NULL;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            Node *node1 = new Node(element);
            head = node1;
        }
        else
        {
            insertion(head, element);
        }
    }

    Node *middle = findMiddle(head);
    Node *last = reverse(middle);

    Node *temp = head;
    Node *ahead = temp->next;

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            head = head;
        else if (i % 2 != 0)
        {
            temp->next = last;
            last = last->next;
            temp = temp->next;
        }
        else if (i % 2 == 0 && i != 0)
        {
            temp->next = ahead;
            ahead = ahead->next;
            temp = temp->next;
        }
    }
    temp->next = NULL;
    print(head);

    return 0;
}

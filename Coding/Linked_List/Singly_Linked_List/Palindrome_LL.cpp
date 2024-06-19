#include <iostream>
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

void insert(Node *head, int element)
{
    Node *data = new Node(element);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = data;
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
    Node *prev = NULL;
    Node *curr = mid;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool check_palindrome(Node *head)
{
    Node *middle = findMiddle(head);
    Node *last = reverse(middle->next);

    Node *temp = head;
    while (last != NULL)
    {
        if (last->data != temp->data)
            return false;
        last = last->next;
        temp = temp->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            Node *node1 = new Node(element);
            head = node1;
        }
        else
            insert(head, element);
    }

    if (check_palindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}

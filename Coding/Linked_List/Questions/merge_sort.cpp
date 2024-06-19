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
        this->next = nullptr; // Update NULL to nullptr
    }
};

Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) // Update NULL to nullptr
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{

    if (left == nullptr)
        return right;

    if (right == nullptr)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted Linked List
    while (left != nullptr && right != nullptr)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != nullptr)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != nullptr)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *merge_sort(Node *head)
{
    // Base case
    if (head == nullptr || head->next == nullptr) // Update NULL to nullptr
    {
        return head;
    }

    // Step-1 Find mid
    Node *mid = findmid(head);

    // Step-2 Breaking LL in two halves left and right
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr; // Isse humne mid k aage ki values ko aage ki ll se tod diya

    // Recursively sort kr rhe
    left = merge_sort(left);
    right = merge_sort(right);

    Node *result = merge(left, right);
    return result;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *node2 = new Node(5);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(10);
    node3->next = node4;
    Node *node5 = new Node(0);
    node4->next = node5;

    print(head);
    head = merge_sort(head);
    print(head);

    return 0;
}

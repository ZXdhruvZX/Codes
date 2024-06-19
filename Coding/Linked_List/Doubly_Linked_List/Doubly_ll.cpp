#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len = len + 1;
        temp = temp->next;
    }
    return len;
}

void insert_at_head(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

void insert_at_tail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->prev = tail;
    temp->next = NULL;
    if (tail != NULL)
        tail->next = temp;
    tail = temp;
}

void insert_at_position(Node *head, Node *tail, int pos, int d)
{
    Node *temp = head;
    Node *newnode = new Node(d);
    int count = 1;
    while (count < pos && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        insert_at_tail(tail, d);
        return;
    }

    newnode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}






int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    // Length of ll
    cout << "length of Linked List is " << length(head);
    cout << endl;

    // Insertion at Head
    insert_at_head(head, 12);

    cout << "Linked List after inserting from head ";
    print(head);
    cout << endl;

    // Insertion at Tail
    insert_at_tail(tail, 15);
    cout << "Linked List after inserting from tail ";
    print(head);
    cout << endl;

    // Insertion at any point
    int pos;
    cout << "Enter the position where you want to enter the element ";
    cin >> pos;
    
    insert_at_position(head, tail, pos, 20);

    print(head);
    cout << endl;
    return 0;

    //Deletion from any point
    int delpos;
    cout<<"Enter the position from from where you want to delete the node"<<endl;
    cin>>delpos;
    deleteNode(delpos, head);
    print(head);
    cout<<endl;
}

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;


    //Constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insert_at_head(Node* &head,int d)
{
    Node *temp= new Node(d);
    temp->next=head;
    head=temp;
}

void print(Node* &head)
{
    Node *temp=head;
    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    //Creating a node
    Node* node1= new Node(10);


    //Creating a head
    Node* head = node1;

    //Printing
    print(head);

    //Inserting values in ll
    insert_at_head(head,12);

    //Printing
    cout<<endl;
    print(head);


    return 0;

}
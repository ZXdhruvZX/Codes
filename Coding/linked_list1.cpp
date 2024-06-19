#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    node* head = NULL;
    node* newnode = NULL;
    int x, n;

    cout << "Enter the size of linked list: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> x;

        newnode = new node;
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            // Find the last node and link the new node to it
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Print the data in the linked list
    cout << "Linked List Data: ";
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Free allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


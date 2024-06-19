#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int val) : data(val), next(NULL) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}

// Main function to test the kReverse function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    std::cout << "Original Linked List: ";
    printList(head);

    // Reverse every 3 nodes
    int k = 3;
    head = kReverse(head, k);

    std::cout << "Linked List after kReverse: ";
    printList(head);

    return 0;
}

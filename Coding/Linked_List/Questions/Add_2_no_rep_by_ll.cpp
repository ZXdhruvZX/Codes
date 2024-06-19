//We are given two ll
//3->4
//2->3->0
//final ans should be like 34+230=264 which should be stored in another ll
//i.e 2->6->4
//Watch lec 51 of babbar



class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head)
    {
        if (!head)
            return NULL;

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        unordered_map<Node *, Node *> oldToNewNode;

        // Create a copy of the linked list without random pointers
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            oldToNewNode[temp] = cloneTail;
            temp = temp->next;
        }

        // Set random pointers for the cloned list
        temp = head;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// See it in GFG and lec 52
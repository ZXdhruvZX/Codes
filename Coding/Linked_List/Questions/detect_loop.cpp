bool detectloop(Node* head)
{
    if(head==NULL)
        return false;

    map<Node *,bool> visited;
    Node* temp=head;

    while(temp!=NULL)
    {
        //Cycle is present
        if(visited[temp]==true)
            return 1;

        visited[temp=true];
        temp=temp->next
    }
    return false;
}
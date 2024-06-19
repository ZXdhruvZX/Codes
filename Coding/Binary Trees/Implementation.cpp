#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left)  ;
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root)
{
    //LNR

    //Base Case
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void preorder(node* root)
{
    //NLR

    //Base Case
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root)
{
    //LRN

    //Base Case
    if(root==NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = NULL;

    // Creating a tree
    root = buildTree(root);

    // Level order
    levelOrderTraversal(root);

    //Inorder Traversal
    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<endl;

    //Preorder Traversal
    cout<<"preorder traversal is: ";
    preorder(root);
    cout<<endl;

    //Postorder Traversal
    cout<<"postorder traversal is: ";
    postorder(root);
    cout<<endl;


    return 0;
}

//7 3 11 1 17 5
// 

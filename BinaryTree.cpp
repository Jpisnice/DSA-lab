#include<iostream>

using namespace std;

//Node Class
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
    Node *root;
    public:
    BinaryTree() { root = NULL; }
    void insert(int value);
    void display();
    void inorder(Node *temp);
    void preorder(Node *temp);
    void postorder(Node *temp);
    Node* search(int value);
    Node* getRoot() { return root; }
};

void BinaryTree::insert(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
        return;
    }
    Node *current = root;
    Node *parent = NULL;
    while(current != NULL)
    {
        parent = current;
        if(value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if(value < parent->data)
        parent->left = temp;
    else
        parent->right = temp;
}



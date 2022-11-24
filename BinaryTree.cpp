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

// recurcive insert in Binary tree


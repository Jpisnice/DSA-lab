//Binary scearch Tree

#include <iostream>
using namespace std;

//Node Class
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

//Binary Search Tree Class
class BST
{
    Node *root;

    public:
    BST() { root = NULL; }
    void insert(int value);
    void display();
    void inorder(Node *temp);
    void preorder(Node *temp);
    void postorder(Node *temp);
    Node* search(int value);
    Node* getRoot() { return root; }
};

// Function to insert nodes in Binary Search Tree
void BST::insert(int value)
{
    Node *temp = new Node;
    Node *parent;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    parent = NULL;

    // If tree is empty
    if (root == NULL)
        root = temp;
    else
    {
        Node *ptr;
        ptr = root;

        // Find parent of node
        while (ptr != NULL)
        {
            parent = ptr;
            if (value > ptr->data)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }

        if (value < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    }
}

// Function to search an element in Binary Search Tree
Node* BST::search(int value)
{
    Node *ptr = root;

    // Search element in Binary Search Tree
    while (ptr != NULL)
    {
        if (value > ptr->data)
            ptr = ptr->right;
        else if (value < ptr->data)
            ptr = ptr->left;
        else
            return ptr;
    }
    return NULL;
}

// Function to display elements of Binary Search Tree
void BST::display()
{
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
}

// Function to perform inorder traversal of Binary Search Tree
void BST::inorder(Node *temp)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// Function to perform preorder traversal of Binary Search Tree
void BST::preorder(Node *temp)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Function to perform postorder traversal of Binary Search Tree

void BST::postorder(Node *temp)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

// Main function
int main()
{
    BST bst;
    int choice, value;

    while (1)
    {
        cout << "1. Insert Element into the tree" << endl;
        cout << "2. Search Element in the tree" << endl;
        cout << "3. Display tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        system("cls");
        switch(choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Enter value to be searched: ";
            cin >> value;
            if (bst.search(value) != NULL)
                cout << "Element " << value << " found in the tree" << endl;
            else
                cout << "Element " << value << " not found in the tree" << endl;
            break;
        case 3:
            bst.display();
            break;
        case 4:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

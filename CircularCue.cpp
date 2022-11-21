
#include <iostream>
using namespace std;

//Node Class
class Node
{
    public:
    int data;
    Node *link;
};

//Circular Queue Class
class Queue
{
    Node *front, *rear;

    public:
    void enQueue(int value);
    int deQueue();
    void displayQueue();
    Queue() { front = rear = NULL; }
};

// Function to create Circular queue
void Queue::enQueue(int value)
{
    Node *temp = new Node;
    temp->data = value;
    if (front == NULL)
        front = temp;
    else
        rear->link = temp;

    rear = temp;
    rear->link = front;
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if ( front == NULL)
    {
        cout << "Queue is empty";
        return 0;
    }

    // If this is the last node to be deleted
    int value; // Value to be dequeued
    if (front == rear)
    {
        value = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else // There are more than one nodes
    {
        Node *temp = front;
        value = temp->data;
        front = front->link;
        rear->link = front;
        free(temp);
    }

    return value;
}

// Function displaying the elements of Circular Queue
void Queue::displayQueue()
{
    Node *temp = front;
    cout << "Elements in Circular Queue are: ";
    while (temp->link != front)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << temp->data << endl;
}

/*Menu driven driver code usiing switch case statements*/
int main()
{
    int Choice;
    Queue q;
    while(1)
    {
        cout<<"1. Insert element to the queue"<<endl;
        cout<<"2. Delete element from the queue"<<endl;
        cout<<"3. Display all the elements of the queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>Choice;
        system("cls");
        switch(Choice)
        {
            case 1:
                int value;
                cout<<"Enter the value to be inserted : ";
                cin>>value;
                q.enQueue(value);
                break;
            case 2:
                cout<<"Deleted value : "<<q.deQueue()<<endl;
                break;
            case 3:
                q.displayQueue();
                break;
            case 4:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
}

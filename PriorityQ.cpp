#include<iostream>
#define MAX 10

using namespace std;

class Item
{
public:
    int data;
    int priority;
};

class PriorityQ
{
private:
    Item *arr;
    int front;
    int rear;
    int size;
public:
    PriorityQ(int size);
    void enqueue(int data, int priority);
    int dequeue();
    void display();
};

PriorityQ::PriorityQ(int size)
{
    this->size = size;
    arr = new Item[size];
    front = -1;
    rear = -1;
}

void PriorityQ::enqueue(int data, int priority)
{
    if(rear == size-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear].data = data;
        arr[rear].priority = priority;
    }
    else
    {
        int i;
        for(i=rear; i>=front; i--)
        {
            if(arr[i].priority > priority)
            {
                arr[i+1].data = arr[i].data;
                arr[i+1].priority = arr[i].priority;
            }
            else
            {
                break;
            }
        }
        arr[i+1].data = data;
        arr[i+1].priority = priority;
        rear++;
    }
}

int PriorityQ::dequeue()
{
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        int data = arr[front].data;
        front++;
        if(front > rear)
        {
            front = rear = -1;
        }
        return data;
    }
}

void PriorityQ::display()
{
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i].data<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    PriorityQ pq(MAX);
    
    int choice, data, priority;
    while(1)
    {
        system("cls");
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                cout<<"Enter priority: ";
                cin>>priority;
                pq.enqueue(data, priority);
                break;
            case 2:
                data = pq.dequeue();
                if(data != -1)
                {
                    cout<<"Dequeued data: "<<data<<endl;
                }
                system("pause");
                break;
            case 3:
                pq.display();
                system("pause");
                break;
            case 4:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}
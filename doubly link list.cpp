#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* link;

    Node(int d)
    {
        this->link=NULL;
        this->data=d;
    }

    Node()
    {
        this->link=NULL;
        this->data=0;
    }
};

class DoublyLinkList{
    private:
    int listCount;
    Node *Head,*Tail;

    public:

    DoublyLinkList()
    {
        Head=Tail=NULL;
    }
    
    void cNode(int data);
    void EnterMultiNode(int n);
    void dNode(int NodeNumber);
    void Display();
    void peek();

};

void DoublyLinkList::EnterMultiNode(int n)
{
    int data;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter data for node "<<i+1<<": ";
        cin>>data;
        cNode(data);
    }
}

void DoublyLinkList::cNode(int data)
{
    Node *FreeshNode=new Node(data);
}

void DoublyLinkList::Display()
{
    Node *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

void DoublyLinkList::peek()
{
    cout<<Head->data;
}

void DoublyLinkList::dNode(int NodeNumber)
{
    Node *temp=Head;
    for(int i=0;i<NodeNumber;i++)
    {
        temp=temp->link;
    }
    temp->link=temp->link->link;
}

int main()
{
    int choice,n;
    int nodN;
    DoublyLinkList obj;
    while(choice!=6)
    {
        cout<<"1. Create a node"<<endl;
        cout<<"2.Enter Multiple Nodes"<<endl;
        cout<<"3. Delete a node"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Peek"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                
                obj.cNode(5);
                break;
            }
            case 2:
            {
                
                cout<<"Enter number of nodes: ";
                cin>>n;
                obj.EnterMultiNode(n);
                break;
            }
            case 3:
            {
                cout<<"Enter node number to delete: ";
                cin>>nodN;
                obj.dNode(nodN);
                break;
            }
            case 4:
            {
                
                obj.Display();
                break;
            }
            case 5:
            {
                
                obj.peek();
                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
            }
        }
}
}
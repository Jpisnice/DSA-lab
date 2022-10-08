#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *link;

    Node()
    {
        data=0;
        link=NULL;
    }

    Node(int d)
    {
        this->data=d;
        this->link=NULL;
    }
};

class linklist
{
    public:
    Node *head;
    int ListCount=0;

    void createNode(int d);
    void PrintList();
    void DeleteNode(int n);
    linklist()
    {
        head=NULL;
    }
};

void linklist::createNode(int d)
{
    Node *freshNode = new Node(d);

    if(head==NULL)
    {
        head=freshNode;
        ListCount++;
    }
    else
    {

    Node *temp=head;

    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=freshNode;
    ListCount++;

    }
}

void linklist::DeleteNode(int n)
{
    Node *temp1=head,*temp2=NULL;
    if(n==1)
    {
        head=head->link;
        delete temp1;
        ListCount--;
        cout << "deleted " << n << " Node" << endl;
    }
    else
    {
        if(n>ListCount)
        {
            cout<<"Bruh Nodes Na Title **face palm**"<<endl;
        }
        else
        {
            int count=1;
            while(count!=n)
            {
                temp2=temp1;
                temp1=temp1->link;
                count++;
            }
            temp2->link=temp1->link;
            delete temp1;
            ListCount--;
            cout<<"deleted "<<n<<" Node"<<endl;
        }
    }

}

void linklist::PrintList()
{
    cout<<"There are "<<ListCount<<" Nodes"<<endl;
    Node* temp=head;
    int ncount=0;
    if(head==NULL)
    {
        cout<<"List Empty"<<endl;
    }
    else
    {   
        ncount++;
        while(temp!=NULL)
        {
            cout<<"Node "<<ncount<<":\t"<<temp->data<<endl;
            temp=temp->link;
            ncount++;
        }
    }
    
}

int main()
{
    int num,choice;
    int k = 0, ctr;
    linklist obj;

    while(choice!=5)
    {   

        {
            cout << "1. Add Node" << endl;
            cout<< "2. Enter Multiple Nodes"<<endl;
            cout << "3. Delete Node" << endl;
            cout << "4. Print List" << endl;
            cout << "5. Exit" << endl;
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
                cout << "Enter the number to be added" << endl;
                cin >> num;
                obj.createNode(num);
                break;
            case 2:
                cout << "Enter the number of nodes to be Added" << endl;
                cin >> ctr;
                while(k<ctr)
                {
                    cout<<endl<<"node "<<k+1<<":";
                    cin>>num;
                    obj.createNode(num);   
                    k++;
                }
                break;
            case 3:
                cout << "Enter the node to be deleted" << endl;
                cin >> num;
                obj.DeleteNode(num);
                break;
            case 4:
                obj.PrintList();
                break;
            case 5:
                cout << "Thanks Bebo" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        }
    }
    return 0;
}

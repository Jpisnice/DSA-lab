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
    Node *tail;
    int ListCount=0;

    void createNode(int d);
    void PrintList();
    void DeleteNode(int n);
    linklist merge(linklist a,linklist b);
    linklist split(linklist a,int n);
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
        tail=freshNode;
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
    tail=freshNode;
    ListCount++;

    }
}

linklist linklist::merge(linklist a,linklist b)
{
    linklist result=a;
    Node * temp=result.head;
    while(temp->link!=NULL)
    temp=temp->link;
    temp->link=b.head;
    result.ListCount=a.ListCount+b.ListCount;
    temp=result.head;
    while(temp->link!=NULL)
    temp=temp->link;
    this->tail=temp;
    return result;
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
            cout<<"Bruh Nodes Na Tittle **face palm**"<<endl;
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
            if((n==ListCount)&&(temp2->link==NULL))
            {
                tail=temp2;
            }
            delete temp1;
            ListCount--;
            cout<<"deleted "<<n<<" Node"<<endl;
        }
    }

}

void linklist::PrintList()
{
    cout<<"There are "<<this->ListCount<<" Nodes"<<endl;
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
    this->ListCount=ncount;
    
}

linklist linklist::split(linklist a,int n)
{
    Node *temp=a.head;
    int ctr=1;
    linklist result;

    if(n>a.ListCount)
    {
        cout << "Cannot split" << endl;
        return a;
    }

    while(temp!=NULL)
    {
        temp=temp->link;
        ctr++;

        if(ctr==n)
        break;
        
    }
    result.head=temp;
    
    result.ListCount=a.ListCount-ctr;
    a.ListCount=a.ListCount-result.ListCount;
    temp=temp->link;
    temp->link=NULL;

    //moidfying original list//
    Node *temp2=a.head;
    int count=1;
    while(temp2!=NULL)
    {
        if(count==a.ListCount)
        {
            temp2->link=NULL;
            break;
        }
        temp2=temp2->link;
        count++;
    }
    a.ListCount=count;
    return result;
}
int main()
{
    int num,choice;
    int k = 0, ctr;
    linklist obj1,obj2,mobj;

    while(choice!=6)
    {   

        {
            cout << "1. Add Node" << endl;
            cout<< "2. Enter Multiple Nodes"<<endl;
            cout<<"3. Merge Another list To existing list"<<endl;
            cout<<"4. Split Entered list into 2 lists"<<endl;
            cout << "5. Delete Node" << endl;
            cout << "6. Print List" << endl;
            cout << "7. Exit" << endl;
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
                cout << "Enter the number to be added" << endl;
                cin >> num;
                obj1.createNode(num);
                break;
            case 2:
                cout << "Enter the number of nodes to be Added" << endl;
                cin >> ctr;
                k=0;
                while(k<ctr)
                {
                    cout<<endl<<"node "<<k+1<<":";
                    cin>>num;
                    obj1.createNode(num);   
                    k++;
                }
                break;
            case 3:
                cout<<"Enter 2nd List"<<endl;
                cout << "Enter the number of nodes to be Added" << endl;
                cin >> ctr;
                k=0;
                while (k < ctr)
                {
                    cout << endl
                         << "node " << k + 1 << ":";
                    cin >> num;
                    obj2.createNode(num);
                    k++;
                }
                mobj=obj1.merge(obj1,obj2);
                mobj.PrintList();
                break;

            case 4:
                cout<<"existing list:"<<endl;
                obj1.PrintList();
                cout<<"from Which Node to split?"<<endl;
                cin>>ctr;
                obj2=obj1.split(obj1,ctr);
                system("cls");
                obj1.PrintList();
                cout<<"------------------------------------"<<endl;
                obj2.PrintList();
                break;

                

            case 5:
                cout << "Enter the node to be deleted" << endl;
                cin >> num;
                obj1.DeleteNode(num);
                break;
            case 6:
                obj1.PrintList();
                break;
            case 7:
                cout << "Thanks Bebo" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        }
    }
    return 0;
}

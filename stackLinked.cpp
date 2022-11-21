#include<iostream>
#define MAX 10
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

class list{
    private:
    int listCount;
    Node *Head,*Tail;

    public:

    list()
    {
        Head=Tail=NULL;
    }
    
    void cNode(int data);
    void dNode(int NodeNumber);
    void Display();
    void peek();

};

void list::cNode(int data)
{
    Node *FreeshNode=new Node(data);
}

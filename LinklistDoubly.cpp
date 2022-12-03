#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *prev,*next;

    node(int data)
    {
        this->data = data;
        this->prev=this->next=NULL;
    }

    node()
    {
        this->data=0;
        this->next=this->prev=NULL;
    }
};

class doubly
{
    private:
    node *head,*tail;
    int size;

    public:
    void insert(int data);
    void del();
};

void doubly::insert(int data)
{
    node *fresh = new node(data);

    if(head==NULL)
    {
        head=fresh;
        tail->prev=head;
        return;
    }
    else
    {
        if()
    }
}


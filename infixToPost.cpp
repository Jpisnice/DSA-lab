#include<iostream>
#include<locale>
#define MAX 20

using namespace std;

class InToPost{

    private:

    char exp[MAX],type[8],popd;
    char post[MAX];
    char stack[MAX];
    char eval[MAX];

    int st;//stack top
    int pt;//post top
    int et; //eval top

    public:
    void getexp();
    void display(char type[]);
    void convert();
    void push2stack(char a);
    void push2post(char a);
    void pop(char type[]);
    bool isemp(char type[]);
    bool isful(char type[]);
    int preced(char ch);
        InToPost()
    {
        
        for(int i=0;i<MAX-1;i++)
        {
            post[i]=stack[i]=eval[i]=' ';
        }
        st = pt = et = -1;
    }


};

void InToPost::getexp()
{
    cout<<"Enter the Expression"<<endl;
    cin>>exp;
    convert();
}

bool InToPost::isemp(char type[])
{
    if(type=="stack")
    {
        if(st==-1)
        return true;
        else
        return false;
    }

    if(type=="post")
    {
        if(pt==-1)
        return true;
        else 
        return false;
    }
}

bool InToPost::isful(char type[])
{
    if (type == "stack")
    {
        if (st == MAX-1)
            return true;
        else
            return false;
    }

    if (type == "post")
    {
        if (pt == MAX-1)
            return true;
        else
            return false;
    }
}

void InToPost::pop(char type[])
{
    if(type=="stack")
    {
        if(isemp(type))
        {
            cout<<type<<" is empty"<<endl;
        }
        else
        {
            popd = stack[st];
            stack[st] = ' ';
            st--;
        }
    }
    if(type=="post")
    {
        if(isemp(type))
        {
            cout<<type<<" is empty"<<endl;
        }
        else
        {
            popd = post[pt];
            post[pt] = ' ';
            pt--;
        }
    }
}

void InToPost::push2stack(char a)
{
    if(isful("stack"))
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        st++;
        stack[st]=a;
    }
}

void InToPost::push2post(char a)
{
    if (isful("post"))
    {
        cout << "postfix is full" << endl;
    }
    else
    {
        pt++;
        post[pt] = a;
    }
}

int InToPost::preced(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1; // Precedence of + or - is 1
    }
    else if (ch == '*' || ch == '/')
    {
        return 2; // Precedence of * or / is 2
    }
    else if (ch == '^')
    {
        return 3; // Precedence of ^ is 3
    }
    else
    {
        return 0;
    }
}

void InToPost::convert()
{
    int i=0;
    char ch;
    while(exp[i]!='\0')
    {
        ch=exp[i];
        if(isalnum(ch))
        {
            push2post(ch);
        }
        else if (ch == '(')
            push2stack('(');

        else if (ch == ')')
        {
            while (stack[st] != '(')
            {
                push2post(stack[st]);
                pop("stack");
            }
            pop("stack");
        }

        else
        {
            while (!isemp("stack") && preced(ch) <= preced(stack[st]))
            {
                push2post(stack[st]);
                pop("stack");
            }
            push2stack(ch);
        }
    
    }
    while (!isemp("stack"))
    {
        push2post(stack[st]);
        pop("stack");
    }

    display("post");
}

void InToPost::display(char type[])
{
    if(type=="post")
    {
        for(int i=0;i<pt;i++)
        {
            cout<<" "<<post[i];
        }
    }
    if (type == "stack")
    {
        for (int i = 0; i < st; i++)
        {
            cout << " " << stack[i];
        }
    }
}

int main()
{
    InToPost obj;
    obj.getexp();
    return 0;
}

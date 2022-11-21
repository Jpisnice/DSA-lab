#include<iostream>
#define MAX 32
using namespace std;

class stack1{
    private:
        int stack[MAX], top;
    public:
        void display();
        void convert(int Num);
        void push(int a);
        bool isful();
        bool isempty();
        int conToDecimal(int number);
        stack1()
        {
            top=-1;
            for(int i=0;i<MAX-1;i++)
            {
                stack[i]=0;
            }
        }


};

bool stack1::isempty()
{
    if(top==-1)
    return true;
    else return false;
}

bool stack1::isful()
{
    if(top==MAX-1)
    return true;
    else return false;
}

void stack1::display()
{
    int d=0;
    if(isempty())
    cout<<"Stack Empty"<<endl;
    else
    {
        d=8-(top+1);
        for(int j=0;j<d;j++)
        cout<<"0";
        for (int i = top; i >= 0; i--)
        {

            cout << stack[i];
        }
        cout << endl;
    }
}

void stack1::push(int a)
{
    if(isful())
    {cout<<"stack full"<<endl;return;}
    else
    {
        top++;
        stack[top]=a;
    }
}

void stack1::convert(int Num)
{

        int i = 0,k;

        while (Num > 0)
        {


            k= Num % 2;
            push(k);

            Num = Num / 2;

            i++;
        }
}

int main()
{
    stack1 obj;
    int number;
    cout<<"Enter Decimal Number"<<endl;
    cin>>number;

    obj.convert(number);
    obj.display();

    
}
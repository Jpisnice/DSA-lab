#include<iostream>
#define SZ 20

using namespace std;

class Insertion{
    private:
    int Arr[SZ];
    int size;

    public:
    Insertion();
    void InsertionSort();
    void Display();
};

Insertion::Insertion(){
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++)
        cin>>Arr[i];

    cout<<"Array Before Sorting:"<<endl;
    Display();
    InsertionSort();
    cout<<"Array After Sorting:"<<endl;
    Display();

}

void Insertion::InsertionSort()
{
    int i,j,key;
    for(i=1;i<=size-1;i++)
    {
        key=Arr[i];
        j=i-1;
        while(j>=0&&Arr[j]>key)
        {
            Arr[j+1]=Arr[j];
            j-=1;
        }
        Arr[j+1]=key;
    }
}

void Insertion ::Display()
{
    for(int i=0;i<size;i++)
    {
        cout<<" "<<Arr[i];
    }
    cout<<endl;
}

int main()
{
    Insertion obj;
    return 0;
}
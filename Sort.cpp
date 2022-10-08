#include<iostream>

using namespace std;

class sort{
    private:
        int array[50], index;
    public:
        
        void Bubble(int a[], int n);
        void Selection(int a[], int n);
        void display();
        void getarrB();
        void getarrS();
};

void sort::getarrB()
{
    cout << "Enter the number of elements" << endl;
    cin >> index;
    cout << "Enter the Array" << endl;
    for (int i = 0; i < index; i++)
        cin >> array[i];

    Bubble(array,index);
}
void sort::getarrS()
{
    cout << "Enter the number of elements" << endl;
    cin >> index;
    cout << "Enter the Array" << endl;
    for (int i = 0; i < index; i++)
        cin >> array[i];

    Selection(array,index);
}

void sort::Bubble(int a[],int n)
{
    int i, j,temp,pass=0;

    

    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            {
                pass++;
                cout << "Pass " <<pass<<":  ";
                display();
                if (a[j] > a[j + 1])
             {
               temp =a[j];
               a[j] =a[j+1];
               a[j+1]=temp;
             }
            }

}

void sort::Selection(int a[], int n)
{
    int i, j, mInx,temp,pass=0;

    for (i = 0; i < n - 1; i++)
    {
        mInx = i;
        pass++;
        cout<<"Pass "<<pass<<": ";
        display();

        for (j = i + 1; j < n; j++)
            if (a[j] < a[mInx])
                mInx = j;

        if (mInx != i)
        {
            temp=a[mInx];
            a[mInx]=a[i];
            a[i]=temp;
        }
            //swap(&arr[mInx], &arr[i]);
    }
}

void sort::display()
{
    for(int i=0;i<index;i++)
    {
        cout<<" "<<array[i];
    }
    cout<<endl;
}

int main()
{
    int choice;
    sort obj;
    while(choice!=3)
    {
        cout<<"How to Sort?"<<endl<<"1.Bubble Sort"<<endl<<"2.Selection Sort"<<endl<<"3.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            system("cls");
            obj.getarrB();
            break;

            case 2:
            system("cls");
            obj.getarrS();
            break;

            case 3:
            break;

            default:
            cout<<"Invalid choice"<<endl;

        }
    }

}



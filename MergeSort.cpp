#include<iostream>
#define MAX 20
using namespace std;

 class Sort
 {
    int arr[MAX];
    int size;
    public:
    void mergeSort(int arr[],int l,int r);
    void merge(int arr[],int l,int r,int m);
    Sort();
 };

 Sort::Sort()
 {
    cout<<"How Many Elements do you want ?"<<endl;
    cin>>size;
    cout<<"Enter your elements"<<endl;
    for(int i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Array Before Sorting:"<<endl;
    for (int i = 0; i < size; i++)
        cout<< arr[i]<<" ";
    cout<<endl;

    mergeSort(arr,0,size-1);

    cout<<"Array After Sorting:"<<endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
 }

void Sort::mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

void Sort::merge(int arr[],int l,int r,int m)
{
    int i=l,j=m+1,k=l;
    int temp[MAX];

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
            
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
            
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int s=l;s<=r;s++)
    {
        arr[s]=temp[s];
    }
}

 int main()
 {
    Sort obj;
    return 0;

 }
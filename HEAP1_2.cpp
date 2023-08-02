#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
        int index=i;
        int left=2*i;
        int right=2*i+1;
        int largest=index;
        if(left<=n && arr[largest]<arr[left])
        {
            largest=left;
        }
        if(right<=n&& arr[largest]<arr[right])
        {
            largest=right;
        }
        if(largest!=index)
        {
            swap(arr[largest],arr[index]);
            index=largest;
            heapify(arr,n,index);
        }
}
void buildheap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}
void heapsort(int arr[],int n)
{
    while(n!=1)
    {
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}
int main()
{
    int arr[]={-1,12,15,13,11,14};
    int n=5;
    buildheap(arr,5);
    cout<<"Printing the heap"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,5);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
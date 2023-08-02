#include<iostream>
using namespace std;
class Heap
{
    public:
    int* arr=new int();
    int size;
    Heap()
    {
        size=0;
    }
    void insert(int value)
    {
        size+=1;
        int index=size;
        arr[index]=value;
        
        //placing
        while(index>1)
        {
            int parentindex=index/2;
            if(arr[parentindex]<arr[index])
            {
                swap(arr[index],arr[parentindex]);
                index=parentindex;
            }
            else
            break;
        }
    }
    int deletee()
    {
        arr[1]=arr[size];
        size--;
        int index=1;
        while(index<size)
        {
            int left=2*index;
            int right=2*index+1;

            int largest=index;

            if(left<size&&arr[largest]<arr[left])
            {

                largest=left;
            }
            if(right<size&&arr[largest]<arr[right])
            {
                largest=right;
            }
            if(largest==index)
            {
                break;
            }
            else
            {
                swap(arr[largest],arr[index]);
                index=largest;
            }
        }
        return arr[1];
    }
   
};
int main()
{
    Heap a;
    // a.arr[0]=-1;
    // a.arr[1]=100;
    // a.arr[2]=50;
    // a.arr[3]=60;
    // a.arr[4]=40;
    // a.arr[5]=45;
    // a.size=5;
    a.insert(50);
    a.insert(30);
    a.insert(70);
    a.insert(80);
    a.insert(40);
    a.insert(100);
    for(int i=0;i<=a.size;i++)
    {
        cout<<a.arr[i]<<" ";
    }
    cout<<endl;
    cout<<a.deletee()<<endl;
    for(int i=0;i<=a.size;i++)
    {
        cout<<a.arr[i]<<" ";
    }
   
}
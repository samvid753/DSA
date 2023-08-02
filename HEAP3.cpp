#include<iostream>
#include<vector>
#include<queue>
 using namespace std;
 class info{
    public:
    int data;
    int rowno;
    int colno;
    info(int dat,int r,int c)
    {
        data=dat;
        rowno=r;
        colno=c;
    }
 };
 class compare{
    public:
    bool operator()(info*a,info*b)
    {
        return a->data>b->data;
    }
 };

 vector<int> mergeksort(vector<vector<int> >& give)
 {
    priority_queue<info*,vector<info*>,compare> minheap;
    for(int i=0;i<give.size();i++)
    {
        info* temp=new info(give[i][0],i,0);
        minheap.push(temp);
    }
    vector<int> arr;
    while(!minheap.empty())
    {
        info* res=minheap.top();
        int tope=res->data;
        int rowe=res->rowno;
        int cole=res->colno;

        arr.push_back(tope);
        minheap.pop();
        if(cole+1<give[rowe].size())
        {
            info* tem=new info(give[rowe][cole+1],rowe,cole+1);
            minheap.push(tem);
        }
        
    }
    return arr;
 }
 //nsorted linked list
 int main()
 {
    vector<vector<int> > give{{1,4,5},{1,3,4},{2,6}};
    vector<int> res=mergeksort(give);
    for(auto i:res)
    cout<<i<<" ";
    cout<<endl;
 }
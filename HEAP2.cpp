#include<iostream>
#include<queue>
using namespace std;
//int getkth smallest
//int getkth largest Leetcode
// pair<bool,int> solve(Node* root)//to check given binary tree is heap or not
// {
//     if(root==NULL)
//     {
//         pair<bool,int> p=make_pair(true,INT_MIN);
//         return p;
//     }
//     if(root->left==NULL && root->right==NULL)
//     {
//         pair<bool,int> p=make_pair(true,root->val);
//         return p;
//     }
//     pair<bool,int> left=solve(root->left);
//     pair<bool,int> right =solve(root->right);
//     if(left.first==true && right.first==true && left.second<root->val && right.second<root->val)
//     {
//         pair<bool,int> p=make_pair(true,root->val);
//         return p;
//     }
//     else
//     {
//         pair<bool,int> p=make_pair(false,root->val);
//         return p;
//     }

// }

//BST to max heap convert inorder to postorder or heapify
//check given tree is complete binary tree
//levelorder
int main()
{
    priority_queue<int> pq; //max heap
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    cout<<pq.top()<< " ";
    pq.pop();
    cout<<pq.top()<< " ";
    cout<<pq.size()<< " ";
    if(pq.empty())
    {
        cout<<"YES"<< " ";
    }
    else
    {
        cout<<"NO"<< " ";
    }
    priority_queue<int,vector<int>,greater<int>> pqq; //min heap
    pqq.push(3);
    pqq.push(6);
    pqq.push(9);
    pqq.push(4);
    pqq.push(8);
    cout<<pqq.top();
     
    return 0;
}
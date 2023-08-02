#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
class Node{
   public:
   int val;
   Node* left;
   Node* right;
   Node(int x)
   {
    this->val=x;
    this->left=NULL;
    this->right=NULL;
   }
};
class Nodedata
{
    public:
    int size;
    int minval;
    int maxval;
    bool valid;
    Nodedata()
    {}
    Nodedata(int size,int mval,int mvall,bool valid)
    {
        this->size=size;
        this->minval=mval;
        this->maxval=mvall;
        this->valid=valid;
    }
};

Node* insertintoBST(Node* root ,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    if(root->val>val)
    {
        root->left=insertintoBST(root->left,val);

    }
    else
    {
        root->right=insertintoBST(root->right,val);
    }
    return root;
}
void takeinput(Node* & root)
{
    int data;
    cin>>data;
    while(data!=-1){
    root=insertintoBST(root,data);
    cin>>data;
    }
}
void level(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            cout<<temp->val<<" ";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }
}
void preorder(Node * root)
{
    if(root==NULL)
    return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node * root)
{
    if(root==NULL)
    return ;
    
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node * root)
{
    if(root==NULL)
    return ;
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
bool search(Node*root,int val)
{
    if(root==NULL)
    return false;
    if(root->val==val)
    return true;
    if(root->val>val)
    return search(root->left,val);
    else
    return search(root->right,val);

}
int min(Node* root)
{
    if(root==NULL)
    return -1;
    while(root->left!=NULL)
    root=root->left;
    return root->val;
}
int max(Node* root)
{
    if(root==NULL)
    return -1;
    while(root->right!=NULL)
    root=root->right;
    return root->val;
}
// void hi(int*& arr)
// {
//     arr[0]=1;
   
// }
Node* deleteNode(Node* root, int key) {
        if(root==NULL)
        return root;
        if(root->val==key)
        {
           if(root->left==NULL && root->right==NULL)
           return NULL;
           if(root->left!=NULL && root->right==NULL)
           {
               Node* child=root->left;
               delete root;
               return child ;
           }
           if(root->left==NULL && root->right!=NULL){
               Node* child=root->right;
               delete root;
           return child ;}
           if(root->left!=NULL && root->right!=NULL)
           {
               int mx=max(root->left);
               root->val=mx;
               root->left=deleteNode(root->left,mx);
               return root;
           }
           
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
void bsttolinkedlist(Node* root,Node*& head)
{
    if(root==NULL)
    return;
    bsttolinkedlist(root->right,head);
    root->right=head;
    if(head!=NULL)
    head->left=root;
    head=root;
    bsttolinkedlist(root->left,head);
    
}
Node* linkedlisttobst(Node*& head,int n)
{
    if(n<=0 || head==NULL)
    return NULL;
    Node* lefttree=linkedlisttobst(head,n-(n/2)-1);
    Node* root=head;
    root->left=lefttree;
    head=head->right;
    root->right=linkedlisttobst(head,n/2);
    return root;
}
void printl(Node * head1)
{
    Node* head=head1;
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->right;
    }
}
int size(Node* head)
{
    Node* temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->right;
    }
    return c;
}
Nodedata lbst(Node* root,int &ans)
{
    if(root==NULL)
    {
        Nodedata temp(0,INT_MAX,INT_MIN,true);
        return temp;
    }
    Nodedata leftkaans=lbst(root->left,ans);
    Nodedata rightkaans=lbst(root->right,ans);
    
    Nodedata currkaans;

    currkaans.size=leftkaans.size+rightkaans.size+1;
    currkaans.minval=min(leftkaans.minval,root->val);
    currkaans.maxval=max(rightkaans.maxval,root->val);

    if(leftkaans.valid && rightkaans.valid && root->val>leftkaans.maxval && root->val<rightkaans.minval)
    {
        currkaans.valid=true;
    }
    else
    {
        currkaans.valid=false;
    }
    if(currkaans.valid)
    ans=max(ans,currkaans.size);

    return currkaans;
    
}
int main()
{
   cout<<"enter"<<endl;
   Node* root=NULL;
   takeinput(root);
   cout<<"LEVEL ORDER"<<endl;
//    level(root);
//    cout<<"PRE ORDER"<<endl;
//    preorder(root);
//    cout<<"\nIN ORDER"<<endl;
//    inorder(root);
//    cout<<"\nPOST ORDER"<<endl;
//    postorder(root);
//    cout<< "\n"<<search(root,1)<<endl;
//    cout<<max(root)<<endl;
//    cout<<min(root)<<endl;
   
   
//    root=deleteNode(root,5);
//    cout<<"LEVEL ORDER AFTER DELETION"<<endl;

   level(root);

   Node* head=NULL;
   bsttolinkedlist(root,head);
  
   printl(head); 
   cout<<endl;   
   Node* root1=linkedlisttobst(head,size(head));  
   level(root1);  
   int ans=0;
   lbst(root1,ans);
   cout<<ans<<" ";
   cout<<" ";
}
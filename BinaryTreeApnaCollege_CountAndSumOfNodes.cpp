#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int val)
    {
        data=val;
        lchild=NULL;
        rchild=NULL;
    }
};

int Count_Nodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int l= Count_Nodes(root->lchild);
    int r= Count_Nodes(root->rchild);

    return l+r+1;
}

void Count_Nodes_UsingRef(Node* root, int &count)
{
    if(root==NULL)
    {
        return ;
    }

    count++;    

    Count_Nodes_UsingRef(root->lchild,count);
    Count_Nodes_UsingRef(root->rchild,count);    
    
}


int Sum_Nodes(Node* root)
{
    if(root==NULL)
        return 0;
    
    int left_sum= Sum_Nodes(root->lchild);
    int rt_sum= Sum_Nodes(root->rchild);

    return left_sum + rt_sum + root->data ;
}


int main()
{
    Node* root= new Node(1);
    root->lchild= new Node(2);
    root->rchild= new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->lchild= new Node(6);
    root->rchild->rchild= new Node(7);

    int c= Count_Nodes(root);
    cout<<"Total no. of nodes = "<< c <<endl;
    // Output: Total no. of nodes = 7

    int count=0;
    Count_Nodes_UsingRef(root,count);
    cout<<"Total no. of nodes using Count_Nodes_UsingRef Method = "<< count <<endl;
    // Output: Total no. of nodes using Count_Nodes_UsingRef Method = 7

    int sum=0;
    sum= Sum_Nodes(root);
    cout<<"Total sum of all nodes in BT is "<<sum<<endl;
    // Output: Total sum of all nodes in BT is 28
}
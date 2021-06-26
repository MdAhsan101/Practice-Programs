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

bool IsBalanced(Node* root, int* cur_ht)
{
    if(root==NULL)
        return true;
    
    int l_ht=0, r_ht=0;

    if(IsBalanced(root->lchild,&l_ht)==false || IsBalanced(root->rchild,&r_ht)==false)
    {
        return false;
    }

    *cur_ht= max(l_ht,r_ht)+1;

    if(abs(l_ht-r_ht)<=1)
    {
        return true;
    }
    return false;
}

int main()
{
    Node* root= new Node(1);
    root->lchild= new Node(2);
    root->lchild->rchild= new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->lchild= new Node(6);
    root->rchild->rchild= new Node(7);

    int cur_ht=0;
    bool ans= IsBalanced(root,&cur_ht);
    cout<<"The BTree is balanced ? : "<<ans<<endl;
    // The BTree is balanced ? : 1
}
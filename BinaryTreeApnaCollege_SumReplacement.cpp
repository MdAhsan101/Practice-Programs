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

int Sum_Replacement(Node* root)
{
    if(root==NULL)
        return 0;

    int l_sum= Sum_Replacement(root->lchild);
    int r_sum= Sum_Replacement(root->rchild);

    root->data= l_sum + r_sum + root->data;

    return root->data;    
}

void InOrder(Node* root)
{
    if(root)
    {
        InOrder(root->lchild);
        cout<<root->data<<" ";
        InOrder(root->rchild);
    }
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

    Sum_Replacement(root);
    InOrder(root);
    // Output: 4 11 5 28 6 16 7

}
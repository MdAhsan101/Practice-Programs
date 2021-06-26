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

int Height(Node* root)
{
    if(root==NULL)
        return 0;

    int l_ht= Height(root->lchild);
    int r_ht= Height(root->rchild);

    return max(l_ht , r_ht) +1;
}

int Diameter(Node* root) // O(n^2)
{
    if(root==NULL)
        return 0;
    int l_ht= Height(root->lchild);
    int r_ht= Height(root->rchild);
    int cur_dia= l_ht + r_ht +1;

    int left_dia= Diameter(root->lchild);
    int rt_dia= Diameter(root->rchild);

    return max(cur_dia, max(left_dia,rt_dia));
}

int Diameter_Optimized(Node* root, int* height)
{
    if(root==NULL)
        return 0;

    int l_ht=0, r_ht=0;
    int left_dia= Diameter_Optimized(root->lchild,&l_ht);
    int rt_dia= Diameter_Optimized(root->rchild,&r_ht);
    int curr_dia= l_ht + r_ht + 1;

    *height= max(l_ht , r_ht) + 1;

    return max(curr_dia, max(left_dia,rt_dia));
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

    int ht= Height(root) - 1;
    cout<<"Total Height = "<< ht <<endl;
    // Output: Total Height = 2

    int dia= Diameter(root);
    cout<<"Diameter of given Btree is "<< dia <<endl;
    //Output: Diameter of given Btree is 5

    ht=0;
    dia= Diameter_Optimized(root,&ht);
    cout<<"Diameter of given Btree is "<< dia <<" and height is "<< ht-1 <<endl;
    //Output: Diameter of given Btree is 5 and height is 2
}
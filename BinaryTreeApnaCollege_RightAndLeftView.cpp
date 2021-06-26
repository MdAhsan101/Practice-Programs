#include<iostream>
#include<queue>
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

void Right_View(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n= q.size();
        for(int i=0; i<n; i++)
        {
            Node* t= q.front();
            q.pop();
            
            if(t->lchild)
            {
                q.push(t->lchild);
            }

            if(t->rchild)
            {
                q.push(t->rchild);
            }

            if(i==n-1)
            {
                cout<<t->data<<" ";
            }

        }
    }
}

void Left_View(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n= q.size();
        for(int i=0; i<n; i++)
        {
            Node* t= q.front();
            q.pop();
            
            if(t->lchild)
            {
                q.push(t->lchild);
            }

            if(t->rchild)
            {
                q.push(t->rchild);
            }

            if(i==0)
            {
                cout<<t->data<<" ";
            }

        }
    }
}

int main()
{
    /*
               1
             /   \
            2      3
          /   \   /
         4    5  6
        /
       8  
        
    */
    Node* root= new Node(1);
    root->lchild= new Node(2);
    root->rchild= new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->lchild= new Node(6);
    root->lchild->lchild->lchild= new Node(8);

    Right_View(root); cout<<endl;
    // Output: 1 3 6 8

    Left_View(root); cout<<endl;
    // Output: 1 2 4 8


}
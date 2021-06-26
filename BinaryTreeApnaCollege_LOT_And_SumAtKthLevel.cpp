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

void LOT(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* p= q.front();
        q.pop();

        if(p!=NULL)
        {
            cout<<p->data<<" ";
            if(p->lchild)
                q.push(p->lchild);
            if(p->rchild)
                q.push(p->rchild);
        }

        if(p==NULL)
        {
            if(q.empty())
                break;
            else
                q.push(NULL);
        }
    }
}

int SumAtKLevel(Node* root,int k) // k=level
{
    queue<Node*> q;
    q.push(root);
    int level=1;
    int sum=0;

    while(!q.empty())
    {
        int s= q.size();
        for(int i=0; i<s; i++)
        {
            Node* p= q.front();
            q.pop();
            if(level==k)
            {
                sum += p->data;
            }
            if(p->lchild)
                q.push(p->lchild);
            if(p->rchild)
                q.push(p->rchild);
        }
        
        level++;
    }
    return sum;
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

    LOT(root); cout<<endl;

    int sum_at_kLevel = SumAtKLevel(root,2);
    cout<<"Sum at Level K is "<<sum_at_kLevel<<endl;
}

/*
Output:

1 2 3 4 5 6 7      
Sum at Level K is 5
*/
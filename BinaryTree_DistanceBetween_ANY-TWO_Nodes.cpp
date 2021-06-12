#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}*root=NULL;

void CreateTree()
{
    int val;
    
    root= (struct Node*) malloc (sizeof(struct Node));
    cout<<"Enter value for root node: ";
    cin>>val;
    
    root->data=val;
    queue<struct Node*> q;
    q.push(root);
    struct Node* p;
    
    while(!q.empty())
    {
        p= q.front();
        q.pop();
        
        cout<<"Enter value for lchild of "<<p->data<<endl;
        cin>>val;
        if(val!=-1)
        {
            struct Node* t= (struct Node*) malloc(sizeof(struct Node));
            t->data = val; t->lchild=t->rchild=NULL;
            p->lchild = t;
            q.push(t);
        }

        cout<<"Enter value for rchild of "<<p->data<<endl;
        cin>>val;
        if(val!=-1)
        {
            struct Node* t= (struct Node*) malloc(sizeof(struct Node));
            t->data = val; t->lchild=t->rchild=NULL;
            p->rchild = t;
            q.push(t);
        }
        
    }

}

void RPreOrder(struct Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        RPreOrder(p->lchild);
        RPreOrder(p->rchild);
    }    
}

void RPostOrder(struct Node* p)
{
    if(p)
    {
        RPostOrder(p->lchild);
        RPostOrder(p->rchild);
        cout<<p->data<<" ";
    }    
}

void RInOrder(struct Node* p)
{
    if(p)
    {
        RInOrder(p->lchild);
        cout<<p->data<<" ";
        RInOrder(p->rchild);
    }    
}

//Note: This function take some node which will act as a root node and search for the given key.
// Returns the level from initial node which is acting as root node to where the key found.
int FindLevelForKey(struct Node* p,int key,int l)
{
    if(p==NULL)
        return -1;
    if(p->data==key)
        return l;
    int left= FindLevelForKey(p->lchild,key,l+1);
    
    if(left!=-1)
        return left;

    return FindLevelForKey(p->rchild,key,l+1);
}

//Note: LCA will return address of Least commin Ancestor
//Least Common Ancestor for two nodes n1, n2
struct Node* LCA(struct Node* p, int n1,int n2) 
{
    if(p==NULL)
        return NULL;
    if(p->data==n1 || p->data==n2)
        return p;

    struct Node* leftLCA= LCA(p->lchild,n1,n2);
    struct Node* rightLCA= LCA(p->rchild,n1,n2); 

    if(leftLCA!=NULL && rightLCA!=NULL)
        return p;
    if(leftLCA==NULL && rightLCA==NULL)
        return NULL;       
    if(leftLCA!=NULL)
        return leftLCA;
    return rightLCA;   
}


int main()
{
    
    CreateTree();

    cout<<"PreOrder: ";
    RPreOrder(root);
    cout<<endl;

    cout<<"PostOrder: ";
    RPostOrder(root);
    cout<<endl;

    cout<<"InOrder: ";
    RInOrder(root);
    cout<<endl;

    cout<<"Enter two node values for which distance to calculate: ";
    int n1, n2;
    cin>>n1>>n2;
    
    struct Node* lca_node= LCA(root,n1,n2);
    int lca_dis= FindLevelForKey(root,lca_node->data,0);
    int n1_dis= FindLevelForKey(root,n1,0);
    int n2_dis= FindLevelForKey(root,n2,0);

    int distance_between_two_nodes = n1_dis + n2_dis -2*lca_dis;
    cout<<"Distance between two nodes "<<n1<<" and "<<n2<<" is "<<distance_between_two_nodes<<endl;
    
}

/*
Output:

Enter value for root node: 10
Enter value for lchild of 10
5
Enter value for rchild of 10
20
Enter value for lchild of 5
4
Enter value for rchild of 5
8
Enter value for lchild of 20
15
Enter value for rchild of 20
25
Enter value for lchild of 4
3
Enter value for rchild of 4
-1
Enter value for lchild of 8
-1
Enter value for rchild of 8
-1
Enter value for lchild of 15
-1
Enter value for rchild of 15
18
Enter value for lchild of 25
-1
Enter value for rchild of 25
-1
Enter value for lchild of 3
-1
Enter value for rchild of 3
-1
Enter value for lchild of 18
16
Enter value for rchild of 18
19
Enter value for lchild of 16
-1
Enter value for rchild of 16
-1
Enter value for lchild of 19
-1
Enter value for rchild of 19
-1
PreOrder: 10 5 4 3 8 20 15 18 16 19 25 
PostOrder: 3 4 8 5 16 19 18 15 25 20 10
InOrder: 3 4 5 8 10 15 16 18 19 20 25
Enter two node values for which distance to calculate: 4 18
Distance between two nodes 4 and 18 is 5
*/
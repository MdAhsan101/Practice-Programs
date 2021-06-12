#include<iostream>
#include<queue>
#include<vector>
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

struct Node* FindLeafNodes(struct Node *p, vector<struct Node*> &v)
{
    if(p==NULL)
        return NULL;
    struct Node* left= FindLeafNodes(p->lchild,v);
    struct Node* right= FindLeafNodes(p->rchild,v);

    if(!p->lchild && !p->rchild)
    {
        v.push_back(p);
        return p;
    }
    
    return p;
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

    cout<<"Enter the limiting distance between any two leaf nodes: ";
    int limit_dist;
    cin>>limit_dist;

    vector<struct Node*> v; //Used to store the address of encountered leaf nodes
    FindLeafNodes(root,v);

    cout<<"All possible pairs of such leaf nodes are as folows: "<<endl;
    for(int i=0; i<v.size()-1; i++)
    {
        struct Node* n1= v[i];
        struct Node* n2;
        struct Node* lca;
        int lca_dist;
        int n1_dist;
        int n2_dist;
        for(int j=i+1; j<v.size(); j++)
        {
            n2= v[j];
            lca= LCA(root,n1->data,n2->data);
            lca_dist= FindLevelForKey(root,lca->data,0);
            n1_dist= FindLevelForKey(root,n1->data,0);
            n2_dist= FindLevelForKey(root,n2->data,0);
            int dbln= n1_dist + n2_dist -2*lca_dist;
            if(dbln<=limit_dist)
                {
                    cout<<"{"<<n1->data <<" "<<n2->data<<"} "<<endl;
                }
        }
        
    }
   
}
/*
My Binary Tree:

                     10
                  /       \
                5          20
              /   \       /   \
             4     8    15     25
           /             \
          3               18 
                         /  \
                        16   19
*/
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

Enter the limiting distance between any two leaf nodes: 5

All possible pairs of such leaf nodes are as folows:
{3 25}
{8 25}
{16 25}
{19 25}
*/
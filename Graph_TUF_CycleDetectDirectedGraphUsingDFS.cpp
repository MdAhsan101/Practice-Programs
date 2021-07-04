#include<bits/stdc++.h>
using namespace std;

bool IsCycleDG(vector<int> *G, int src, int *vis, int *dfsvis)
{
    vis[src]=1;
    dfsvis[src]=1;

    for(auto v: G[src])
    {
        if(!vis[v])
        {
            if(IsCycleDG(G,v,vis,dfsvis))
                return true;
        }
        else if(dfsvis[v]==1)
        {
            return true;
        }
    }
    dfsvis[src]=0;
    return false;
}

bool CycleDetectDG(vector<int> G[], int n)
{
    int vis[n+1]; int dfsvis[n+1];
    memset(vis,0,sizeof(vis));
    memset(dfsvis,0,sizeof(dfsvis));

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(IsCycleDG(G,i,vis,dfsvis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cout<<"Enter no. of nodes and edges resp. for directed graph:";
    int n,m;
    cin>>n>>m;
    vector<int> G[n+1];

    cout<<"Now input all the "<< m <<" edges of directed graph (start node, end node):\n";
    int u,v;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
    }

    bool ans= CycleDetectDG(G,n);
    cout<<"The directed graph has cycle ? : "<<ans<<endl;
    return 0;
}

/*

Output 1:
1--->2--->3--->4
     ^    |    |
     |    !    !
     7    6--->5
    / ^  
   !   \
   8--->9


Enter no. of nodes and edges resp. for directed graph:9 10
Now input all the 10 edges of directed graph (start node, end node):
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9
9 7
The directed graph has cycle ? : 1

Output 2:
1--->2--->3--->4
     ^    |    |
     |    !    !
     7    6--->5
    /  \ 
   !    !
   8--->9


Enter no. of nodes and edges resp. for directed graph:9 10
Now input all the 10 edges of directed graph (start node, end node):
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9
7 9
The directed graph has cycle ? : 0
*/
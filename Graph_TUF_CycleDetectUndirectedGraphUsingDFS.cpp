#include<bits/stdc++.h>
using namespace std;

bool IsCyclic(vector<int> *G, vector<int> &visited, int n, int src, int parent)
{
    visited[src]=1;

    for(auto v: G[src])
    {
        if(!visited[v])
        {
            if(IsCyclic(G,visited,n,v,src))
                return true;
        }
        else if (visited[v]==1 && v!=parent)
        {
            return true;
        }
    }
    return false;
}

bool CycleDetectDFS(vector<int> G[],int n)
{
    vector<int> visited(n+1,0);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(IsCyclic(G,visited,n,i,-1))
                return true;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter the number of nodes and edges the undirected graph has: ";
    int n,m; 
    cin>>n>>m;
    vector<int> G[n+1];

    cout<<"Now enter the edges (s,e): \n";
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ans= CycleDetectDFS(G,n);
    cout<<"Is the graph G is cyclic ? : "<<ans<<endl;
}

/*
Output 1:
1----2---3----4
     |   |    |
     |   |    |
     7   6----5
  


Enter no. of nodes and edges resp. for directed graph:7 7
Now input all the 10 edges of directed graph (start node, end node):
1 2
2 3
3 4
4 5
3 6
6 5
7 2

Is the graph G is cyclic ? : 1

Output 2:
1----2---3----4
     |   |    |
     |   |    |
     7   6    5

1 2
2 3
3 4
4 5
3 6
7 2

Is the graph G is cyclic ? : 0
*/
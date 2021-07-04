/* This type of soting only applicable to directed acyclic graph oonly */

#include<bits/stdc++.h>
using namespace std;


void TopoSortUtil(vector<int> *G, vector<int> &vis, stack<int> &stk, int u)
{
    vis[u]=1;
    for(auto v: G[u])
    {
        if(!vis[v])
            TopoSortUtil(G,vis,stk,v);
    }
    stk.push(u);
}

vector<int> TopoSortDFS(vector<int> *G, int n)
{
    stack<int> stk;
    vector<int> vis(n+1,0);
    vector<int> topoans;   
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            TopoSortUtil(G,vis,stk,i);                        
        }
    }

    while(!stk.empty())
    {
        topoans.push_back(stk.top());
        stk.pop();
    }
    return topoans;
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

    vector<int> TopoSortAns= TopoSortDFS(G,n);
    cout<<"The topological sort of the given directed (acyclic) graph is: ";
    for(auto ele: TopoSortAns)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}

/*
Output:

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

The topological sort of the given directed (acyclic) graph is: 7 8 9 1 2 3 6 4 5
*/
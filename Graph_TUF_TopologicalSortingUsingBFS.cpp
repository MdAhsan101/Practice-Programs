/* This type of soting only applicable to directed acyclic graph oonly */

#include<bits/stdc++.h>
using namespace std;


vector<int> TopoSortBFS(vector<int> *G, int n)
{
    queue<int> q;
    vector<int> InDegree(n+1);

    // Calculating Indegree for each node
    for(int u=1; u<=n; u++)
    {
        for(auto v:G[u])
            InDegree[v]++;
    }

    // Now pushing all '0' Indegree nodes into queue
    for(int i=1; i<=n; i++)
    {
        if(InDegree[i]==0)
            q.push(i);
    }

    vector<int> topoans;
    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        topoans.push_back(u);

        for(auto v: G[u])
        {
            InDegree[v]--;
            if(InDegree[v]==0)
                q.push(v);            
        }
                
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

    vector<int> TopoSortAns= TopoSortBFS(G,n);
    cout<<"The topological sort of the given directed (acyclic) graph is: ";
    for(auto ele: TopoSortAns)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}

/*
Output:
Note: A graph can have multiple topological order.

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

The topological sort of the given directed (acyclic) graph is: 1 7 2 8 3 9 4 6 5
*/
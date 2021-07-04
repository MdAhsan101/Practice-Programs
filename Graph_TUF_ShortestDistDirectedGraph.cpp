#include<bits/stdc++.h>
#define Inf INT_MAX
using namespace std;

void TopoSortUtil(vector<pair<int,int>> *G, vector<int> &vis, stack<int> &stk, int u)
{
    vis[u]=1;
    for(auto v: G[u])
    {
        if(!vis[v.first])
            TopoSortUtil(G,vis,stk,v.first);
    }
    stk.push(u);
}

stack<int> TopoSortDFS(vector<pair<int,int>> *G, int n)
{
    stack<int> stk;
    vector<int> vis(n+1,0);
       
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            TopoSortUtil(G,vis,stk,i);                        
        }
    }

    return stk;
}

int* ShortestDistDG(vector<pair<int,int>> G[],int n,int src)
{

    stack<int> stk= TopoSortDFS(G,n);
    int* dist= new int[n+1];
    
    for(int i=0; i<=n; i++)
        dist[i]=Inf;

    dist[src]=0;

    while(!stk.empty())
    {
        int u= stk.top();
        stk.pop();

        if(dist[u]!=Inf)
        {
            for(auto v:G[u])
            {
                if(dist[v.first]>(dist[u]+v.second))
                {
                    dist[v.first]= dist[u]+v.second;
                }
            }
        }
    }
    return dist;    
}

int main()
{
    cout<<"Enter no. of nodes and edges resp. for directed graph:";
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> G[n+1]; // pair<node,wt>

    cout<<"Now input all the "<< m <<" edges of directed graph (start node, end node, weight):\n";
    int u,v,w;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        G[u].push_back({v,w}); // Inserting pair value
    }

    cout<<"Enter the source node: ";
    int src; cin>>src;
    int *d= ShortestDistDG(G,n,src);

    cout<<"V:"; for(int i=1; i<=n; i++) cout<<i<<" ";
    cout<<endl;
    cout<<"D:";

    for(int i=1; i<=n; i++)
    {
        (d[i]==Inf) ? (cout<<"Inf "):(cout<<d[i]<<" ");
    } 
}

/*
 (2)   (3)  (6)
1--->2--->3--->4
|      (2)^    ^(1)
|(1)      | (4)|
--------->5--->6

Output:

Enter no. of nodes and edges resp. for directed graph:6 7
Now input all the 7 edges of directed graph (start node, end node, weight):
1 2 2
1 5 1
2 3 3
5 3 2
5 6 4
3 4 6
6 4 1

Enter the source node: 1
V:1 2 3 4 5 6 
D:0 2 3 6 1 5

*/

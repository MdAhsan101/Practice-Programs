#include<bits/stdc++.h>
using namespace std;

void ShortestDistUDG(vector<int> G[], int n, int *dist, int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(auto v: G[u])
        {
            if(dist[v]>(dist[u]+1))
            {
                dist[v]= dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    cout<<"Enter no. of nodes and edges resp. for directed graph:";
    int n,m;
    cin>>n>>m;
    vector<int> G[n+1];
    int dist[n+1];
    for(int i=0; i<=n; i++)
        dist[i]=INT_MAX;

    cout<<"Now input all the "<< m <<" edges of directed graph (start node, end node):\n";
    int u,v;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int src;
    cout<<"Enter the source node: ";
    cin>>src;

    ShortestDistUDG(G,n,dist,src);

    cout<<"V:"; for(int i=1; i<=n; i++) cout<<i<<" ";
    cout<<endl;
    cout<<"D:";

    for(int i=1; i<=n; i++)
    {
        (dist[i]==INT_MAX) ? (cout<<"Inf "):(cout<<dist[i]<<" ");
    }    

}

/*
Output:
Note: Its an undirected graph
1----2---3----4
     |   |    |
     |   |    |
     7   6----5
    /  \ 
   |    |
   8----9
   
Enter no. of nodes and edges resp. for directed graph:9 10
Now input all the 10 edges of directed graph (start node, end node):
1 2
2 3
2 7
3 4
4 5
3 6
6 5
7 8
7 9
8 9
Enter the source node: 1
V:1 2 3 4 5 6 7 8 9 
D:0 1 2 3 4 3 2 3 3
*/
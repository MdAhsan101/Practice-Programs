#include<bits/stdc++.h>
using namespace std;

void Djikstra(vector<pair<int,int>> G[], int n, int src)
{
    vector<int> dist(n+1,INT_MAX);
    
    // Data Structure for Min Heap of pair<dist,node>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
    dist[src]=0;
    min_heap.push({0,src});

    while(!min_heap.empty())
    {
        pair<int,int> cur_node= min_heap.top();
        min_heap.pop();
        int u= cur_node.second;

        for(auto v: G[u])
        {
            if(dist[v.first]>(dist[u]+v.second))
            {
                dist[v.first]=dist[u]+v.second;
                min_heap.push({dist[v.first],v.first});
            }
        }
    }
    
    cout<<endl;
    cout<<"Distance from source "<<src<<" are : ";
    for(int i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
}



int main()
{
    cout<<"Enter no. of nodes and edges resp. for directed graph:";
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> G[n+1];
    int dist[n+1];
    for(int i=0; i<=n; i++)
        dist[i]=INT_MAX;

    cout<<"Now input all the "<< m <<" edges of directed graph (start node, end node, weight):\n";
    int u,v,wt;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
        G[v].push_back({u,wt});
    }

    int src;
    cout<<"Enter the source node: ";
    cin>>src;

    Djikstra(G,n,src);

}

/*
Output:

Enter no. of nodes and edges resp. for directed graph:5 6
Now input all the 6 edges of directed graph (start node, end node, weight):
1 2 2
1 4 1
2 5 5
2 3 4
4 3 3
3 5 1
Enter the source node: 1   

Distance from source 1 are : 0 2 4 1 5
*/
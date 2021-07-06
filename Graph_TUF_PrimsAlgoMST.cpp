#include<bits/stdc++.h>
#define Inf INT_MAX
using namespace std;

void Prims_MinSpanningTree(vector<pair<int,int>> G[], int n, int src)
{
    vector<int> included(n+1,0);
    vector<int> wt(n+1,Inf);
    vector<int> parent(n+1,-1);

    wt[src]=0;
    parent[src]=-1;

    for(int cnt=1; cnt<=n-1; cnt++)
    {
        int min_wt= INT_MAX;
        int u;
        
        for(int i=1; i<=n; i++)
        {
            if((included[i]==0)&&(min_wt > wt[i]))
            {
                min_wt= wt[i];
                u= i;
            }
        }

        included[u]=1;

        for(auto next_node: G[u])
        {
            int v= next_node.first;
            int weight= next_node.second;

            if(included[v]==0 && wt[v]>weight)
            {
                wt[v]= weight;
                parent[v]= u;
            }
        }
    }

    cout<<"\nThe resulting edges of min spanning tree are:\n";
    for(int i=2; i<=n; i++)
        cout<<parent[i]<<"-->"<<i<<endl;

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

    Prims_MinSpanningTree(G,n,src);
    
}

/*
Output:

Enter no. of nodes and edges resp. for directed graph:5 6
Now input all the 6 edges of directed graph (start node, end node, weight):
1 2 2
1 4 6
2 4 8
2 5 5
2 3 3
5 3 7
Enter the source node: 1

The resulting edges of min spanning tree are:
1-->2
2-->3
1-->4
2-->5
*/
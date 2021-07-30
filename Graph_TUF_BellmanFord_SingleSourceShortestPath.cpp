#include<bits/stdc++.h>
#define I 32767
using namespace std;

struct node
{
    int u;
    int v;
    int edge_cost;
};

void BellmanFord(node edges[],int n, int m, int src)
{
    vector<int> dist(n+1,I);
    dist[src]=0;

    for(int k=1; k<=n-1; k++)
    {
        for(int i=1; i<=m; i++)
        {
            int u= edges[i].u;
            int v= edges[i].v;
            int uv_cost= edges[i].edge_cost;
            //Relaxing adjacent vertex in case condition satisfy
            if((dist[u]+uv_cost)<(dist[v]))
            {
                dist[v]= (dist[u]+uv_cost);
            }
        }
    }

    bool flag= false;
    //Trying to relax adjacent edges again in order to detect negative cycle in graph
    for(int i=1; i<=m; i++)
        {
            int u= edges[i].u;
            int v= edges[i].v;
            int uv_cost= edges[i].edge_cost;
            if((dist[u]+uv_cost)<(dist[v]))
            {
                flag= true;
                break;
            }
        }
    
    if(flag)
    {
        cout<<"Negative cycle detected."<<endl;
    }
    else
    {
        cout<<"The shortest cost calculated through BellmanFord from src("<<src<<") to :"<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<"vertex ("<<i<<") is "<<dist[i]<<endl;
        }
    }
}



int main()
{
    cout<<"Enter no. of nodes present in the graph: ";
    int n; 
    cin>>n;
    cout<<"Enter no. of edges present in the graph: ";
    int m; 
    cin>>m;
    node edges[m+1];
    cout<<"Now enter all edges(u,v,cost(u,v))"<<endl;
    for(int i=1; i<=m; i++)
    {
        cout<<"Enter details of edge "<<i<<endl;
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[i].u= u;
        edges[i].v= v;
        edges[i].edge_cost= cost;
    }
    int src;
    cout<<"Please enter the src vertex: ";
    cin>>src;
    BellmanFord(edges,n,m,src);
}

/*
Output:

Enter no. of nodes present in the graph: 6  
Enter no. of edges present in the graph: 7
Now enter all edges(u,v,cost(u,v))
Enter details of edge 1
1 2 5
Enter details of edge 2
2 3 -2
Enter details of edge 3
2 6 -3
Enter details of edge 4
3 5 3
Enter details of edge 5
4 3 6
Enter details of edge 6
4 5 -2
Enter details of edge 7
6 4 1
Please enter the src vertex: 1
The shortest cost calculated through BellmanFord from src(1) to :
vertex (1) is 0
vertex (2) is 5
vertex (3) is 3
vertex (4) is 3
vertex (5) is 1
vertex (6) is 2
*/


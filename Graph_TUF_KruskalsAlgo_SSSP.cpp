#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;

    node(int a, int b, int c)
    {
        u= a;
        v= b;
        wt= c;
    }
};

bool cmp_asc_wt(node n1, node n2)
{
    return n1.wt < n2.wt;
}

int FindParent(int node, vector<int> &parent)
{
    if(parent[node]==node)
        return node;
    return parent[node]= FindParent(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int par1= FindParent(u,parent);
    int par2= FindParent(v,parent);

    if(rank[par1]>rank[par2])
    {
        parent[par2]= par1;
    }
    else if(rank[par2]>rank[par1])
    {
        parent[par1]= par2;
    }
    else
    {
        parent[par1]= par2;
        rank[par2]++;
    }
}


void Kruskals(vector<node> &edge, int n, int src)
{
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);

    for(int i=0; i<=n; i++)
        parent[i]= i;
    
    sort(edge.begin(), edge.end(), cmp_asc_wt);

    int cost=0;
    vector<pair<int,int>> mst_edge;

    for(auto e: edge)
    {
        if(FindParent(e.u, parent) != FindParent(e.v, parent))
        {
            cost += e.wt;
            unionn(e.u,e.v,parent,rank);
            mst_edge.push_back({e.u,e.v});
        }
    }

    cout<<"\nTotal cost of MST: "<<cost<<endl<<endl;;
    for(auto edg: mst_edge)
    {
        cout<< edg.first <<"-->"<< edg.second <<endl;
    }   
}

int main()
{
    cout<<"Enter no. of nodes and edges resp. for directed graph:";
    int n,m;
    cin>>n>>m;
    vector<node> edge;
    int dist[n+1];

    cout<<"Now input all the "<< m <<" edges of directed graph (start node, end node, weight):\n";
    int u,v,wt;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>wt;
        edge.push_back(node(u,v,wt));
    }

    int src;
    cout<<"Enter the source node: ";
    cin>>src;

    Kruskals(edge,n,src);   
}

/*
Output:

Enter no. of nodes and edges resp. for directed graph:6 9
Now input all the 9 edges of directed graph (start node, end node, weight):
5 1 4
5 4 9
4 1 1
1 2 2
4 2 3
4 3 5
2 3 3
2 6 7
3 6 8
Enter the source node: 5

Total cost of MST: 17

4-->1
1-->2
2-->3
5-->1
2-->6
*/

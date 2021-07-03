#include<bits/stdc++.h>
using namespace std;

bool IsBipartiteDFS(vector<int> G[], int n, int *color, int src, int parent)
{
    
    for(auto v:G[src])
    {
        if(color[v]==-1)
        {
            color[v]= 1-color[parent];
            if(!IsBipartiteDFS(G,n,color,v,src))
            {
                return false;
            }
        }
        else if(color[v]==color[src])
        {
            return false;
        }
    }
    return true;    
}

bool CheckBipartiteDFS(vector<int> G[],int n)
{
    int color[n+1];
    memset(color,-1,sizeof(color)); // Here 'memset' initialzes all array element by -1

    for(int i=1; i<=n; i++)
    {
        if(color[i]==-1)
        {
            color[i]=1;
            if(!IsBipartiteDFS(G,n,color,i,-1))
            {
                return false;
            }
        }        
    }
    return true;
}

int main()
{
    cout<<"Enter no. of node and edges resp. the graph have : ";
    int n,m; cin>>n>>m;
    vector<int> G[n+1];

    int u,v;
    cout<<"Now input starting and end nodes of each edges."<<endl;
    for(int i=1; i<=m; i++)
    {   
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ans= CheckBipartiteDFS(G,n);
    cout<<"Is the graph is Bipartite ? : "<<ans<<endl;
}

/*

 1-----2
 |     |   
 |     |  
 |     | 
 4-----3 

Output1:

Enter no. of node and edges resp. the graph have : 4 4
Now input starting and end nodes of each edges.
1 2
1 4
4 3
2 3
Is the graph is Bipartite ? : 1

 1-----2 
 |     | \  
 |     |  5
 |     | /
 4-----3 

Output2:

Enter no. of node and edges resp. the graph have : 5 6
Now input starting and end nodes of each edges.
1 2
1 4
4 3
2 3
2 5
3 5
Is the graph is Bipartite ? : 0
*/ 
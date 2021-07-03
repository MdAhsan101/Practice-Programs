#include<iostream>
#include<vector>
using namespace std;

void DFS_Util(vector<int> G[],int n, vector<int> &dfs, vector<int> &visited, int u)
{
    dfs.push_back(u);
    for(auto v: G[u])
    {
        if(!visited[v])
        {
            visited[v]=1;
            DFS_Util(G,n,dfs,visited,v);
        }
    }
}

vector<int> DFS(vector<int> G[],int n )
{
    vector<int> visited(n+1,0);
    vector<int> dfs;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            DFS_Util(G,n,dfs,visited,i);            
        }
    }  
    return dfs;      
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

    vector<int> dfs_res= DFS(G,n);
    cout<<"DFS: ";
    for(auto node: dfs_res)
        cout<<node<<" ";
}

/*

 1-----2
 | \   | \  
 |  \  |  4
 |   \ | /
 5-----3 

Output:

Enter no. of node and edges resp. the graph have : 5 7
Now input starting and end nodes of each edges.
1 2
1 3
1 5
2 3
2 4
3 4
3 5

DFS: 1 2 3 4 5
*/ 
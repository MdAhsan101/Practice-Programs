#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(vector<int> G[],int n)
{
    vector<int> visited(n+1,0);
    vector<int> bfs;
    queue<int> q;

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            q.push(i);

            while(!q.empty())
            {
                int u= q.front();
                bfs.push_back(u);
                q.pop();

                for(auto v: G[u])
                {
                    if(!visited[v])
                    {
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return bfs;
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

    vector<int> bfs_res= BFS(G,n);
    cout<<"BFS: ";
    for(auto node: bfs_res)
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

BFS: 1 2 3 5 4
*/ 
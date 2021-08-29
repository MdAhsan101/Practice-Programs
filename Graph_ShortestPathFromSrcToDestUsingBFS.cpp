/*
Ques: A magician can perform 'k' times magic to reduce any route to length 0.
You need to find the shortest distance for magician to reach destination after performing magic.
*/ 

#include<bits/stdc++.h>
using namespace std;

int ShortestPathDist(vector<vector<int>> &G,int &n, int src, int &dest, int count)
{
    vector<int> visited(n,0);
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int s=q.size();
        for(int i=0; i<s; i++)
        {   
            int u=q.front();
            q.pop();
            for(auto v:G[u])
            {
                if(!visited[v])
                {
                    visited[v]=1;
                    if(v==dest)
                    {
                        return count+1; 
                    }
                    q.push(v);
                }
            }
        }
        count++;
    }
    return -1;
}
int main()
{
    int n,m;
    cout<<"Enter no. of nodes and edges for graph:";
    cin>>n>>m;
    vector<vector<int>> G(n);

    int u,v;
    cout<<"Enter graph edges with weights (u,v):\n";
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int src,dest;
    cout<<"Enter the src and dest points: ";
    cin>>src>>dest;

    int count=0;
    int ans= ShortestPathDist(G,n,src,dest,count);
    cout<<"The shortest path from source to destination is "<<ans<<endl;

}

/*
Output:

Enter no. of nodes and edges for graph:8 9
Enter graph edges with weights (u,v):
0 1
1 3
1 4
3 6
4 6
4 2
6 7
2 7
2 5
Enter the src and dest points: 0 7
The shortest path from source to destination is 4
*/
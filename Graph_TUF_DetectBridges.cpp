#include<bits/stdc++.h>
using namespace std;

// tin= time of insertion, ltin= lowest time of insertion of adjacent nodes
void Detect_Bridges(int cur_node,int parent_node,vector<int> *G, int &timer, vector<int> &vis, vector<int> &tin, vector<int> &ltin)
{
    vis[cur_node]=1;
    tin[cur_node]= ltin[cur_node]= timer++;
    
    for(auto adj_node: G[cur_node])
    {
        if(adj_node==parent_node)
            continue;
        else if(!vis[adj_node])
        {
            Detect_Bridges(adj_node,cur_node,G,timer,vis,tin,ltin);
            
            ltin[cur_node]= min(ltin[cur_node],ltin[adj_node]);
            
            if(ltin[adj_node]>tin[cur_node])
            {
                cout<<"{"<<cur_node<<","<<adj_node<<"}"<<endl;                
            }
        }
        else // if adj_node is visited
        {
            ltin[cur_node]= min(tin[adj_node],ltin[cur_node]);
        }
    }
}


int main()
{
    cout<<"Enter no. of nodes in graph:";
    int n; 
    cin>>n;
    vector<int> G[n+1];
    cout<<"Enter the no. of edges of given graph: ";
    int m; cin>>m;
    cout<<"Now enter the edges(src,dest) of graph:\n";
    int u,v;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int timer=0;
    vector<int> vis(n+1,0);
    vector<int> tin(n+1);
    vector<int> ltin(n+1);

    cout<<"\nFollwing are the bridges detected in graph: \n";
    Detect_Bridges(1,-1,G,timer,vis,tin,ltin);
    
}

/*

    1---2
  / |   |
13  4---3
    |
    5
     \
      6
     / \
    7   9
     \ /
      8
      |
      10--11
      |  /
      12

Output:

Enter no. of nodes in graph:13
Enter the no. of edges of given graph: 15
Now enter the edges(src,dest) of graph:
1 13
1 2
1 4
2 3
3 4
4 5
5 6
6 7
6 9
7 8
9 8
8 10
10 11
10 12
11 12

Follwing are the bridges detected in graph: 
{1,13}
{8,10}
{5,6}
{4,5}
*/
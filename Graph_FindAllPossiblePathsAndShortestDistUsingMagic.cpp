/*
Ques: A magician can perform 'k' times magic to reduce any route to length 0.
You need to find the shortest distance for magician to reach destination after performing magic.
*/ 

#include<bits/stdc++.h>
using namespace std;

void ShortestPathDist(vector<vector<pair<int,int>>> &G,int &n, pair<int,int> uw, int &dest, vector<vector<pair<int,int>>> &allpathwts,vector<pair<int,int>> &pathwts,vector<int> &visited)
{
    int u=uw.first;
    int wt=uw.second;
    visited[u]=1;
    pathwts.push_back({u,wt});
    if(u==dest)
    {
        allpathwts.push_back(pathwts);
        visited[u]=0;
        pathwts.pop_back();
        return;
    }
    for(auto pr:G[u])
    {
        int v=pr.first;
        int w=pr.second;
        if(!visited[v])
        {      
            ShortestPathDist(G,n,{v,w},dest,allpathwts,pathwts,visited);            
        }
    }
    visited[u]=0;
    pathwts.pop_back();
}
int main()
{
    int n,m;
    cout<<"Enter no. of nodes and edges for graph:";
    cin>>n>>m;
    vector<vector<pair<int,int>>> G(n);

    int u,v,wt;
    cout<<"Enter graph edges with weights (u,v,wt):\n";
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
        G[v].push_back({u,wt});
    }
    int src,dest;
    cout<<"Enter the src and dest points: ";
    cin>>src>>dest;

    int k; // Perform k-times magic to reduce the longest edge 
    // to zero and calculate shortest distance
    cout<<"Enter k value: "; cin>>k;

    vector<vector<pair<int,int>>> allpathwts; //each row contains vector of pair<node,weight> though which dfs traversal took to reach dest
    vector<pair<int,int>> pathwts;
    vector<int> visited(n,0);
    visited[src]=1;
    ShortestPathDist(G,n,{src,0},dest,allpathwts,pathwts,visited);
    cout<<"All possible node traversed to reach dest are as follows:"<<endl;
    priority_queue<int> maxheap;
    int ans=INT_MAX; int sum=0,count;
    for(auto vec: allpathwts)
    {
        sum=0;
        count=1;
        for(auto pr:vec)
         {
             int node=pr.first; int weight=pr.second;
             cout<<"{"<<node<<","<<weight<<"}, ";
             maxheap.push(weight);
         }
        cout<<endl<<endl;;
        while(!maxheap.empty())
        { 
            if(count<=k){
                maxheap.pop();
            }
            else{
                sum+=maxheap.top();
                maxheap.pop();
            }
            count++;
        }
        ans=min(ans,sum);
    }
    cout<<"The smallest possible distance that magician will cover after 'k' magics to reach destination will be : ";
    cout<<ans<<endl;

}

/*
Output:

Enter no. of nodes and edges for graph:8 9
Enter graph edges with weights (u,v,wt):
0 1 5
1 3 3
1 4 2
3 6 4
4 6 5
4 2 3
6 7 1
2 7 6
2 5 2
Enter the src and dest points: 0 6
Enter k value: 2
All possible node traversed to reach dest are as follows:
{0,0}, {1,5}, {3,3}, {6,4},

{0,0}, {1,5}, {4,2}, {6,5},

{0,0}, {1,5}, {4,2}, {2,3}, {7,6}, {6,1}, 

The smallest possible distance that magician will cover after 'k' magics to reach destination will be : 2
*/
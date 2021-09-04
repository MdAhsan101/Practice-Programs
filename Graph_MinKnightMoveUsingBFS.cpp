#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int si=KnightPos[0], sj=KnightPos[1];
	    int ti=TargetPos[0], tj=TargetPos[1];
	    vector<vector<int>> vis(N+1,vector<int> (N+1,0));
	    int di[]={-2, -1, 1, 2, -2, -1, 1, 2};
        int dj[]={-1, -2, -2, -1, 1, 2, 2, 1};
	    
	    queue<pair<int,int>> q;
	    q.push({si,sj});
	    int step=0;
	    while(!q.empty())
	    {
	        
	        int s=q.size();
	        while(s--)
	        {
	            int ci=q.front().first;
	            int cj=q.front().second;
	            vis[ci][cj]=1;
	            if(ci==ti && cj==tj)
	            {
	                return step;
	            }
    	        q.pop();
    	        for(int k=0; k<8; k++)
    	        {
    	            int ni= ci+di[k];
    	            int nj= cj+dj[k];
    	            if(ni>=1 && ni<=N && nj>=1 && nj<=N && vis[ni][nj]==0)
    	            {
    	                q.push({ni,nj});
    	            }
    	        }
	        }
	        if(!q.empty())
	        {
	            step++;
	        }
	        
	    }   
	}

int main()
{
    vector<int> kpos={4,5};
    vector<int> tpos={1,1};
    int x= minStepToReachTarget(kpos,tpos,6);
    cout<<x<<endl;

}
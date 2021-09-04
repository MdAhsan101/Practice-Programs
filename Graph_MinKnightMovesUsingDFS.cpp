#include<bits/stdc++.h>
using namespace std;

void DFS(int i,int j,int &ti,int &tj,int &minstep,int step, int &n)
    {
        static vector<vector<int>> visited(n+1,vector<int> (n+1,0));
        if(i<1 || j<1 || i>n || j>n || visited[i][j]==1 || step>n)
        {
            return;            
        }
       
        if(i==ti && j==tj)
        {
            minstep=min(minstep,step);
            return;
        }
        
        //static int di[]={-1,1,-2,2,-2,2,-1,1};
        //static int dj[]={-2,-2,-1,-1,1,1,2,2};
        static int di[]={-2, -1, 1, 2, -2, -1, 1, 2};
        static int dj[]={-1, -2, -2, -1, 1, 2, 2, 1};
        
        visited[i][j]=1;
        //cout<<i<<" "<<j<<endl;
        for(int k=0;k<8;k++)
        {
            int ni=i+di[k];
            int nj=j+dj[k];
             
            
            DFS(ni,nj,ti,tj,minstep,step+1,n);
            
        }
        visited[i][j]=0;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int i=KnightPos[0], j=KnightPos[1];
	    int ti=TargetPos[0], tj=TargetPos[1];
	    int minstep=INT_MAX;
	    DFS(i,j,ti,tj,minstep,0,N);
	    return minstep;
	}

int main()
{
    vector<int> kpos={4,5};
    vector<int> tpos={3,2};
    int x= minStepToReachTarget(kpos,tpos,6);
    cout<<x<<endl;

}
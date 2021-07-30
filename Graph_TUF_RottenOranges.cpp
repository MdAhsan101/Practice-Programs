#include<bits/stdc++.h>
using namespace std;

int RottenOranges(vector<vector<int>> &grid)
{
    int r=grid.size();
    int c=grid[0].size();
    int total_org=0, rotten_org=0;
    queue<pair<int,int>> q;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]!=0)
                total_org++;
            if(grid[i][j]==2)
            {
                q.push({i,j});
                rotten_org++;
            }
        }
    }

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int minute_counts=0;
    while(!q.empty())
    {
        int s= q.size();
        while(s--)
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int adj_x= x+dx[i];
                int adj_y= y+dy[i];
                if(adj_x>=0 && adj_x<c && adj_y>=0 && adj_y<r)
                {
                    if(grid[adj_x][adj_y]==1)
                    {
                        q.push({adj_x,adj_y});
                        grid[adj_x][adj_y]=2;
                        rotten_org++;
                    }
                }
            }
        }

        if(!q.empty())
            minute_counts++;
    }
    return (total_org==rotten_org) ? (minute_counts):-1;
}

int main()
{
    // 2= rotten_org, 1=fresh_org, 0=empty_cell
    vector<vector<int>> grid={
        {2,0,0,2},
        {1,0,0,1},
        {1,1,0,1},
        {0,0,0,1}
    };
    
    int minutes= RottenOranges(grid);
    if(minutes!=-1)
    {
        cout<<"All ogranges will be rotten in "<<minutes<<" minutes."<<endl;
    }
    else
    {
        cout<<"Its not possible that all oranges will be rotten in this problem."<<endl;
    }
    
}

// Output: All ogranges will be rotten in 3 minutes.
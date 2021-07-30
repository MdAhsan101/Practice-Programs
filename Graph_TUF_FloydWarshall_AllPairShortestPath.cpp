#include<bits/stdc++.h>
#define I 32767
using namespace std;
int n=4;
int A[5][5]={
    {0,0,0,0,0},
    {0,0,3,I,7},
    {0,8,0,2,I},
    {0,5,I,0,1},
    {0,2,I,I,0}
};

int main()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=k && j!=k && i!=j)
                {
                    A[i][j]= min(A[i][j],(A[i][k]+A[k][j]));
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }


}

/*
Output:

0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0
*/
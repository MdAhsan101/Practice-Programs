#include<iostream>
using namespace std;

bool IsSafe(int** arr,int i, int j,int n)
{
    if(i<n && j<n && arr[i][j]==1)
    {
        return true;
    }
    return false;
}

bool FindPath(int** arr, int i, int j, int n,int **soln)
{
    if(i==(n-1) && j==(n-1))
    {
        soln[i][j]=1;
        return true;
    }
    
    if(IsSafe(arr,i,j,n))
    {
        soln[i][j]=1;
        if(FindPath(arr,i+1,j,n,soln))
        {
            return true;
        }
        if(FindPath(arr,i,j+1,n,soln))
        {
            return true;
        }
        soln[i][j]=0;
        return false;
    }  
    return false;
}

int main()
{
    cout<<"Give size of matrix: ";
    int n;
    cin>>n;
    int** A= new int* [n];
    int** soln= new int* [n];
    
    cout<<"Enter all elements of given matrix correctly. "<<endl;
    for(int i=0; i<n; i++)
    {
        A[i]= new int [n];
        for(int j=0; j<n; j++)
            cin>>A[i][j];
    }

    for(int i=0; i<n; i++)
    {
        soln[i]= new int [n];
        for(int j=0; j<n; j++)
            soln[i][j]=0;
    }

    if(FindPath(A,0,0,n,soln))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                if(soln[i][j]==1)
                    cout<<"{"<<i<<","<<j<<"} ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++)
    {
        delete[] A[i];
        delete[] soln[i];
    }

}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/

/*
Give size of matrix: 5
Enter all elements of given matrix correctly. 
1
0
1
0
1
1
1
1
1
1
0
1
0
1
0
1
0
0
1
1
1
1
1
0
1

{0,0} {1,0} {1,1} {1,2} {1,3} {2,3} {3,3} {3,4} {4,4}
*/
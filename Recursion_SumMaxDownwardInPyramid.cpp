#include<iostream>
using namespace std;

int const n=4;
int movedown(int a[n][n],int const n,int i,int j)
{
    int sum=0;
    if(i==n-1)
    {
        return a[i][j]; //*(a+(i*n)+j)
    }

    if(a[i+1][j]>a[i+1][j+1]) //*((a+(i+1)*n)+j)  (*(a+(i+1)*n)+(j+1))
    {
        sum = (a[i][j]+movedown(a,n,i+1,j)); //*(a+(i*n)+j)
    }
    else
    {
        sum = (a[i][j]+movedown(a,n,i+1,j+1)); // *(a+(i*n)+j)
    }
    return sum;
}

int main()
{
    //Initialize Pryramid 2D array.
    int const n=4;
    int a[n][n]={
        {3,0,0,0},
        {7,4,0,0},
        {2,4,6,0},
        {8,5,9,3}
    };
    int max_sum=0;
    int i=0, j=0;
    max_sum = movedown(a,n,i,j);
    cout<<"Max Sum along Pyramid is "<<max_sum<<endl;
} 

/*
Output:

Max Sum along Pyramid is 23
*/
#include<iostream>
#include<climits>
using namespace std;

int MinSizeSubArray(int* a,int n,int x)
{
    int sum=0;
    int min_size=INT_MAX;

    int front=0,back=0;
    while(front<n && back<n)
    {
        while(sum<=x && front<n)
        {
            sum += a[front++];
        }
        while(sum>x && back<n)
        {
            min_size= min(min_size,(front-back));
            sum= sum-a[back++];
        }
    }
    return min_size;
}

int main()
{
    int arr[]={1,4,45,6,10,19};
    int x=51, n=6;
    int ans= MinSizeSubArray(arr,n,x);
    cout<< ans <<endl;     // Output: 3
}
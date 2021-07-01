#include<iostream>
#include<climits>
using namespace std;

int MaxSumSubArray(int* a,int n,int x, int k)
{
    int sum=0;
    int max_sum=INT_MIN;

    for(int i=0; i<k; i++)
    {
        sum+=a[i];
    }
    if(sum<x)
    {
        max_sum=sum;
    }

    int back=0;
    for(int front=k; front<n; front++)
    {
        sum += a[front]-a[back++];
        if(sum<x)
        {
            max_sum= max(max_sum,sum);
        }
    }
    return max_sum;
}

int main()
{
    int arr[]={7,5,4,6,8,9};
    int n=6, x=20, k=3;
    int ans= MaxSumSubArray(arr,n,x,k);
    cout<<ans<<endl; // Output: 18
}
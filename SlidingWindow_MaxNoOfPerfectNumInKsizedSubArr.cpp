#include<iostream>
#include<math.h>
using namespace std;

bool IsPerfect(int num)
{
    int sum=1;
    for(int i=2; i<=num-1; i++)
    {
        if(num%i==0)
        {
            sum+=i;
        }
    }
    
    if(sum==num) { return true;}
    else
        return false;
}

int MaxSizeSubArray(int* a, int n, int k)
{
    int sum=0;
    for(int i=0; i<k; i++)
    {
        sum += a[i];
    }

    int res= sum;
    int i=k, j=0;
    while(i<n && j<n)
    {
        sum+= a[i++]-a[j++];
        res= max(res,sum);
    }
    return res;
}

int MaxPerfectNumSubArrPossible(int* a, int n, int k)
{
    for(int i=0; i<n; i++)
    {
        if(IsPerfect(a[i]))
        {
            a[i]=1;
        }
        else
        {
            a[i]=0;
        }
    }
    return MaxSizeSubArray(a,n,k);
}

int main()
{
    int arr[]= {28,2,3,6,496,99,8128,24};
    int k=4;
    int n=8;

    cout<<MaxPerfectNumSubArrPossible(arr,n,k)<<endl;
    // Output: 3
}
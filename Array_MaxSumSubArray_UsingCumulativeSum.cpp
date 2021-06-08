//O(n^2)
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int c_sum[n+1];
    c_sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        c_sum[i]= c_sum[i-1] + a[i-1];
    }
    int  max_sum = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        int cur_sum=0;
        for(int j=0; j<i; j++)
        {
            cur_sum = c_sum[i] - c_sum[j];
            max_sum = max(cur_sum,max_sum);
        }
    }
    cout<<"Max Subarray sum found in given array is "<<max_sum<<endl;
    return 0;
}

/*
Output:

Enter the size of array: 7
2 -3 2 1 4 -5 1
Max Subarray sum found in given array is 7
*/
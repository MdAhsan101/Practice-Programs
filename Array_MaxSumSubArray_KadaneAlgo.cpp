// O(n) , Kadane_Algorithm
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

    int max_sum= INT_MIN;
    int cur_sum=0 , si=0, ei=0;
    for(int i=0; i<n; i++)
    {
        cur_sum += a[i];
        ei = i;
        max_sum = max(max_sum, cur_sum);

        if(cur_sum<0)
        {cur_sum=0; si= i+1;}
    }
    if(si!=n)
    {
        cout<<"MaxSum_SubArray is "<<max_sum<<endl;
    }
    return 0;
}

/*
Output:

Enter the size of array: 7
2 -3 2 1 4 -5 1
Max Subarray sum found in given array is 7
*/
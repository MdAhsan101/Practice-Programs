#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={1,3,9,10,8,12,6};
    int target_sum= 24;
    int n= 7;
    sort(arr, arr+n);

    for(int i=0; i<n-2; i++)
    {
        int low=i+1; 
        int high= n-1;
        while(low<high)
        {
            int cur_sum= arr[i]+arr[low]+arr[high];
            if(cur_sum==target_sum)
            {
                cout<<arr[i]<<" "<<arr[low]<<" "<<arr[high]<<endl;
                low++;
                high--;
            }
            else if(cur_sum<target_sum)
                low++;
            else if( cur_sum>target_sum)
                high--;
        }
    }
}

/*
Output:

3 9 12
6 8 10
*/

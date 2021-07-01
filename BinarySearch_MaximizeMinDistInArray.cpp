#include<iostream>
using namespace std;

bool IsDistPossible(int* a,int n, int k, int dist)
{
    int cnt=1;
    int cur_pos= a[0];
    for(int i=0; i<n; i++)
    {
        if(abs(a[i]-cur_pos)>=dist)
        {
            cnt++;
            cur_pos= a[i];
        }
        if(cnt==k)
        {
            return true;
        }
    }
    return false;
}


// k= No. of elements to select from given array that satisfy all such condition
int Largest_MinPossibleDist(int *a,int n,int k) 
{
    int left=a[0], right=a[n-1];
    int ans=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(IsDistPossible(a,n,k,mid))
        {
            left= mid+1; ans= max(mid,ans);
        }
        else
        {
            right= mid-1;
        }
    }
    return ans;

}


int main()
{
    int arr[]={1,2,5,7,11,12};
    int k=3;
    int ans= Largest_MinPossibleDist(arr,6,k);
    cout<<"The largest min distance possible for "<< k <<" elements of given array is "<< ans<<endl;
    // Output: The largest min distance possible for 3 elements of given array is 5
}
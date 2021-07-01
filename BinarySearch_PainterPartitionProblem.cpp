#include<iostream>
#include<climits>
using namespace std;

bool IsFeasible(int* a,int n,int painters, int barrier)
{
    int s=1;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>barrier){ return false;}
        else
        {
            if((sum+a[i])>barrier)
            {
                sum=a[i]; s++;
                if(s>painters)
                    return false;
            }
            else
            {
                sum+=a[i];
            }
        }
    }
    return true;
}

int PainterPartition(int *a, int n, int painters)
{
    int total=0, maxi=INT_MIN, ans=INT_MAX;
    for(int i=0; i<n; i++)
    {
        maxi= max(a[i],maxi);
        total += a[i];
    }

    int low=maxi, high=total;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(IsFeasible(a,n,painters,mid))
        {
            high= mid-1;
            ans= min(ans,mid);
        }
        else
        {
            low= mid+1;
        }
    } 
    return ans;
}

int main()
{
    int arr[]={10,20,30,40};
    int painters_avail=2;
    int ans= PainterPartition(arr,4,painters_avail);
    cout<<"The min time taken for "<<painters_avail<<" painter available is "<< ans <<endl;
}

/*
Output:
The min time taken for 2 painter available is 60
*/
#include<iostream>
#include<climits>
using namespace std;

bool IsFeasible(int* a,int n,int stud, int barrier)
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
                if(s>stud)
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

int AllocateMinPossiblePages(int *a, int n, int stud)
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
        if(IsFeasible(a,n,stud,mid))
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
    int arr[]={12,34,67,90};
    int stud=2;
    int ans= AllocateMinPossiblePages(arr,4,stud);
    cout<<"The min pages that must be allocated " <<"for "<<stud<<" students is "<< ans <<endl;
}

/*
Output:
The min pages that must be allocated for 2 students is 113
*/
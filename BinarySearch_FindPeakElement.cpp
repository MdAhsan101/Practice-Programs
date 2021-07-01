#include<iostream>
using namespace std;

int FindPeakElementIndex(int *a, int n, int low, int high)
{
    int mid= (low+high)/2;
    if((mid==0 || a[mid-1]<a[mid]) && (mid==n-1 || a[mid]>a[mid+1]))
    {
        return mid;
    }
    else if(mid>0 && a[mid-1]>a[mid])
    {
        return FindPeakElementIndex(a,n,low,mid-1);
    }
    else
    {
        return FindPeakElementIndex(a,n,mid+1,high);
    }
}

int main()
{
    int arr[]={1,3,2,4,1,5,3};
    int n=7;
    int idx= FindPeakElementIndex(arr,n,0,n-1);
    cout<<"The first peak element i.e "<<arr[idx]<<" is found at index "<< idx <<endl;
    // Output: The first peak element i.e 4 is found at index 3
}
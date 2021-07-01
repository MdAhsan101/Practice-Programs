#include<iostream>
using namespace std;

int FindKeyInRotatedArray(int *a, int n, int key, int low, int high)
{
    if(low>high)
        return -1;

    int mid=(low+high)/2;
    if(a[mid]==key)
        return mid;
    
    if(a[low]<=a[mid])
    {
        if(key>=a[low] && key<=a[mid])
            return FindKeyInRotatedArray(a,n,key,low,mid-1);
        else
            return FindKeyInRotatedArray(a,n,key,mid+1,high);
    }
    else
    {
        if(key>=a[mid] && key<=a[high])
            return FindKeyInRotatedArray(a,n,key,mid+1,high);
        else
            return FindKeyInRotatedArray(a,n,key,low,mid-1);
    }
    
}


int main()
{
    int arr[]={40,50,60,70,80,10,20,30};
    int n=8;
    int key=20;
    int idx= FindKeyInRotatedArray(arr,n,key,0,n-1);
    cout<<"The key found at index "<<idx<<endl;
    // Output: The key found at index 6
}
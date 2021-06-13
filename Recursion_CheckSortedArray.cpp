#include<iostream>
using namespace std;

bool check_sort(int *arr, int i, int n)
{
    if(i==n-1)
        return true;
    bool x= check_sort(arr,i+1,n);
    return (arr[i]<arr[i+1])&&(x);
}

int main()
{
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<endl;
    cout<<check_sort(a,0,n);
}

/*
Output:

Enter size of array: 5
1 2 3 4 5

1

Enter size of array: 5
3 2 5 1 0

0
*/
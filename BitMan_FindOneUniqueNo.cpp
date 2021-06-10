#include<iostream>
using namespace std;

int OneUniqueNo(int *a, int n)
{
    int xorsum=0;
    for(int i=0; i<n; i++)
        xorsum = xorsum^a[i];
    return xorsum; 
}

int main()
{
    int s[]={1,2,1,3,2}; // Note: 3 ouccur only one time while 1 and 2 ocuur twice.
    cout<<OneUniqueNo(s,5); 
}
/*
Output: 3
*/
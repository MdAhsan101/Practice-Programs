#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of elements in array: "; 
    cin>>n;
    cout<<"Enter the max value of element present in array";
    int m;
    cin>>m;
    
    int* a= new int[n];
    int* ind= new int [m+1];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=m; i++)
    {
        ind[i]=-1;
    }

    int min_ind=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(ind[a[i]]==-1) {ind[a[i]]=i;}
        else{ 
            if(ind[a[i]]<min_ind)
            {
                min_ind= ind[a[i]];
            }        
         }
    }
    cout<<"The first ocuurance found in array is for element: "<<a[min_ind];
    delete[] a;
    delete[] ind;
}
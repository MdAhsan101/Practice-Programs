#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter n=";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the array element: ";
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int i=n-1;
    while(i>=0)
    {
        if(a[i]==0)
        {
            int j=i;
            while(j<n-1)
            {
                a[j]=a[j+1];
                j++;
            }
            a[j]=0;
        }
        i--;
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

/*
Output:

Enter n=8
Enter the array element: 1 0 2 3 0 4 0 3
1 2 3 4 3 0 0 0
*/
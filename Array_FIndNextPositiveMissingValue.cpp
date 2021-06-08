#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    const int N= 1e6+2; // from 0 to (10^6 + 1)
    bool ind[N];

    for(int i=0; i<n; i++)
    {
        if(a[i]>=0) { ind[a[i]]=true;}
        else { ind[a[i]]=false;}
    }

    for(int i=1; i<n ;i++)
    {
        if(ind[i]==false)
        {
            cout<<i<<" is missing "<<endl;
            return 0;
        }
    }
    cout<<"No positive value is missing from the givrn array."<<endl;
    return 0;
}

/*
Output:

Enter the size of array: 6
0 -9 1 3 -4 5
2 is missing
*/
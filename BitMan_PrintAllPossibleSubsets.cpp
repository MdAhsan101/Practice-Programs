#include<iostream>
using namespace std;

void AllPossibleSubsets(char *a, int n) // n= size of array
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
            {cout<<a[j]<<" ";}
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    char carray[n];
    for(int i=0; i<n; i++)
        cin>>carray[i];
    AllPossibleSubsets(carray,n);
    return 0;
}

/*
Output:

4
a b c d

a
b
a b
c 
a c
b c
a b c
d
a d
b d
a b d
c d
a c d
b c d
a b c d
*/
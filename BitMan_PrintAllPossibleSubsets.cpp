#include<iostream>
using namespace std;

void AllPossibleSubsets(char *a, int n) // n= size of array
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
            {cout<<a[n-1-j]<<" ";}
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

3
a b c

c   
b   
c b 
a   
c a 
b a
c b a
*/
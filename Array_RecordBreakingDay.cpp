#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int* a= new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int rbn= -1; // Record breaking number
    int rbd= 0; // Record breaking day
    int count=0;

    for(int i=0; i<=n-2; i++)
    {
        if((a[i]>rbn)&&(a[i+1]<a[i]))
        {rbn= a[i]; rbd= i; count++;}
    }
    if(rbn<a[n-1]) {rbd= n-1; rbn= a[n-1]; count++; }
    delete[] a;

    cout<<"Max Record Breaking day:"<<rbd+1<<endl;
    cout<<"Max Record Breaking number is: "<<rbn<<endl;
    cout<<"Number of Record Breaking Days: "<<count<<endl;
}

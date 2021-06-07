#include<iostream>
using namespace std;

int main()
{
    int cur_len=2;
    int max_len=2;
    int max_si=0, max_ei=1;
    int cur_si=0;

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int* a= new int[n];
    cout<<"Now enter array elements:\n";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int pd=a[1]-a[0];

    for(int i=2;i<=n-1;i++)
    {
        if(pd==(a[i]-a[i-1]))
        {
            cur_len++;
            if(max_len<cur_len)
            {
                max_len=cur_len;
                max_si=cur_si;
                max_ei= i;
            }
        }
        else
        {
            cur_len=2;
            pd=a[i]-a[i-1];
            cur_si= i-1;
        }
    }

    cout<<"MaxLen of subarray is "<<max_len<<endl;
    cout<<"Max subarray is ";
    for(int i=max_si; i<=max_ei; i++)
        cout<<a[i]<<" ";
}
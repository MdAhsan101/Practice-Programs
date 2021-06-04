#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n= ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int j;
        for(j=0; j<=n-i; j++)
        {
            cout<<"  ";
        }
        
        for(;j<=n; j++)
        {
            cout<<"* ";
        }
        
        for(;j<=n+i-1;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n; i>=1; i--)
    {
        int j;
        for(j=0; j<=n-i; j++)
        {
            cout<<"  ";
        }
        
        for(;j<=n; j++)
        {
            cout<<"* ";
        }
        
        for(;j<=n+i-1;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

/*
Output:

Enter n= 5
          * 
        * * * 
      * * * * * 
    * * * * * * *
  * * * * * * * * *
  * * * * * * * * *
    * * * * * * *
      * * * * *
        * * *
          *
*/
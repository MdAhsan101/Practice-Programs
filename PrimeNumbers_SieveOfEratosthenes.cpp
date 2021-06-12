#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter last value upto which prime no. is to find: ";
    int n;
    cin>>n;

    int check[n+1]={0}; //only initializes zero with this way of using {}
    
    for(int i=2;i<=n;i++)
    {
        for(int j=i*i ;j<=n; j+=i)
        {
            if((j%i==0) && (check[j]==0))
            {
                check[j]=i;
            }
        }
    }

    //Printing all prime numbers calculated
    for(int i=2; i<=n; i++)
    {
        if(check[i]==0)
            cout<<i<<" ";
    }
}

/*
Output:

Enter last value upto which prime no. is to find: 50
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
*/
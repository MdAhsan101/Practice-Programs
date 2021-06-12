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
        if(check[i]==0)
            check[i]=i;;
        for(int j=i*i ;j<=n; j+=i)
        {
            if((j%i==0) && (check[j]==0))
            {
                check[j]=i;
            }
        }
    }

    while(n!=1)
    {
        cout<< check[n] <<" ";
        n = n/check[n];
    }
}

/*
Output:

Enter last value upto which prime no. is to find: 50
2 5 5
*/
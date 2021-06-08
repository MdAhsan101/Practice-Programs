#include<iostream>
#include<climits>
using namespace std;

struct Data
    {
        int i;
        int j;
        bool y;
        Data (int a, int b, bool c)
        {
            int i= a;
            int j= b;
            bool y= c; 
        }
        Data ()
        {
            int i= 0;
            int j= 0;
            bool y= false; 
        }
    };

struct Data CheckTwoElementsSum(int a[],int &n,int given_sum)
{

    int low=0, high= n-1;  
    struct Data X(0,0,false);  
    while(low<high)
    {
        int cur_sum = a[low]+a[high];
        if(cur_sum == given_sum)
        {
            X.i= low; X.j=high; X.y=true;
            return X;
        }
        else if(cur_sum > given_sum) {high--;}
        else { low++;}
    }
    cout<<endl;
    return X;
}

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

    struct Data X;  
    int sum;
    cout<<"Enter sum value: ";
    cin>>sum;

    X= CheckTwoElementsSum(a,n,sum);
    if(X.y==true)
    {
        cout<<"Element "<<a[X.i]<<" and "<<a[X.j]<<" pairs to form "<<sum<<endl;
    }
    else
    {
        cout<<"No such element pair present."<<endl;
    }
}

/*
Output:

Enter the size of array: 8
1 3 4 6 11 19 20 25
Enter sum value: 23
Element 3 and 20 pairs to form 23
*/
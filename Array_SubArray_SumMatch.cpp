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
    int s;
    cout<<"Enter the sum value for which subgroup to match: ";
    cin>>s;

    int i=0, j=0, st=-1, en=-1, sum=0;
    while((j<n)&&(sum<=s))
    {
        sum += a[j];
        if(sum==s)
        {
            st=i+1; en=j+1; // As we have index value starting with 1 in ques.
            cout<<st<<" "<<en<<endl;
            return 0;
        }
        j++;
    }
    
    while(j<n)
    {
        while(sum>=s)
        {
            sum -= a[i];
            i++;
            if(sum==s)
            {
                st=i+1; en=j; // As we have index value starting with 1 in ques.
                cout<<st<<" "<<en<<endl;
                return 0;
            }            
        }       
        sum += a[j];
        j++;
    }
    cout<<"No such subarray exist."<<endl;
    return 0;
    
}

/*
Output:

Enter the size of array: 5
1 2 3 7 5
Enter the sum value for which subgroup to match: 12
2 4
*/

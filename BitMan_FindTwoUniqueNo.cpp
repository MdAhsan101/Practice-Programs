#include<iostream>
using namespace std;

int CheckSetbit(int n, int pos)
{
    return (n && (n & (1<<pos))!=0);
}

void TWO_UniqueNo(int a[],int n)
{
    int totalxorsum=0;
    for(int i=0; i<n; i++)
    {
        totalxorsum= totalxorsum^a[i];
    }

    //Now finding the position of first '1' from end of binary format of given no.
    int temp= totalxorsum;
    int setbit=0;
    int pos=0;

    while((temp & 1)==0)
    {
        temp=temp>>1;
        pos++;
    }

    //Doing xorsum for all such elements where '1' is present at 'pos'
    int first_unique_no = 0;
    for(int i=0; i<n; i++)
    {
        if(CheckSetbit(a[i],pos))
        {
            first_unique_no = first_unique_no^a[i];
        }
    }

    
    cout<<"first_unique_no: "<<first_unique_no<<endl;
    cout<<"second_unique_no: "<<(totalxorsum^first_unique_no)<<endl;
}

int main()
{
    int s[]={1,2,1,3,4,2}; // Note: 3 and 4 ouccur only one time while 1 and 2 ocuur twice.
    TWO_UniqueNo(s,6);
}

/*
Output:
first_unique_no: 3
second_unique_no: 4
*/

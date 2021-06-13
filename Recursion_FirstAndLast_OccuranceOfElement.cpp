#include<iostream>
using namespace std;

int first_occ(int *arr, int n, int i, int key)
{
    if(i==n)
        return -1;
    if(arr[i]==key)
        return i;
    return first_occ(arr,n,i+1,key);
}

int last_occ(int *arr, int n, int i, int key)
{
    if(i==n)
        return -1;
    int x= last_occ(arr,n,i+1,key);

    if(x!=-1)
        return x;

    if(arr[i]==key)
        {return i;}

    return x;
}

int main()
{
    int A[]={1,2,5,4,6,7,2,5,4,3};
    int n=10;

    cout<<"Enter element to find: ";
    int ele;
    cin>>ele;
    cout<<"First Occurance of "<<ele<<" is at index "<<first_occ(A,n,0,ele)<<endl;
    cout<<"Last Occurance of "<<ele<<" is at index "<<last_occ(A,n,0,ele)<<endl;

}

/*
Output:
Enter element to find: 4
First Occurance of 4 is at index 3
Last Occurance of 4 is at index 8
*/
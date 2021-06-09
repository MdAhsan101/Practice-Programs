#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the size of matrix:";
    cin>>n>>m;
    cout<<"Enter all "<<n*m<<" elements for the matrix:"<<endl;
    int** a= new int* [n];
    for(int i=0; i<n; i++)
    {
        a[i]=  new int [m];
        for(int j=0; j<m; j++)
        {
          cin>>a[i][j];
        }
    }

    cout<<"My Matrix is : \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n-1, j=0;
    cout<<"\nEnter the value to search in the given matrix: ";
    int key;
    cin>>key;
    while((i>=0 && i<n)&&(j>=0 && j<m))
    {
        if(a[i][j]==key)
        {
            cout<<"Element found at ("<<i<<","<<j<<") "<<endl;
            return 0;
        }
        else if(key>a[i][j])
        {j++;}
        else {i--;}
    }
    cout<<"Element not found."<<endl;
    for(int i=0; i<n; i++)
    {
        delete[] a[i];
    }
    delete(a);
    return 0;
}

/*
Output:

Enter the size of matrix:3 3
Enter all 9 elements for the matrix:
1 2 5 3 4 7 7 8 10
My Matrix is : 
1 2 5
3 4 7
7 8 10

Enter the value to search in the given matrix: 2
Element found at (0,1)
*/
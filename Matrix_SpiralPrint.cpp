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

    int row_front=0, row_end=n-1, col_front=0, col_end=m-1;

    cout<<"\nThe spiral sequence is as follows: ";
    while((col_front<=col_end)&&(row_front<=row_end))
    {
        for(int j=col_front; j<= col_end; j++)
        {
            cout<<a[row_front][j]<<" ";
        }
        row_front++;
        
        for(int i=row_front; i<= row_end; i++)
        {
            cout<<a[i][col_end]<<" ";
        }
        col_end--;

        for(int j=col_end; j>= col_front; j--)
        {
            cout<<a[row_end][j]<<" ";
        }
        row_end--;

        for(int i=row_end; i>= row_front; i--)
        {
            cout<<a[i][col_front]<<" ";
        }
        col_front++;
        
    }
    for(int i=0; i<n; i++)
    {
        delete[] a[i];
    }
    delete(a);
    return 0;
}

/*
Output:

Enter all 9 elements for the matrix:
1 2 3 4 5 6 7 8 9
My Matrix is : 
1 2 3
4 5 6
7 8 9

The spiral sequence is as follows: 1 2 3 6 9 8 7 4 5
*/

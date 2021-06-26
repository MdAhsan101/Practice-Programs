#include<iostream>
using namespace std;

int Merge(int* A, int low, int mid, int high)
{
    int b_size= high-low+1;
    int B[b_size];
    int i=low, j=mid+1, k=0;
    int inv_count=0;

    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i]; k++; i++;
        }
        else if(A[i]>A[j])
        {
            B[k]=A[j]; k++; j++;
            
            // Putting condition to find inversion count
            // i.e when A[i]>A[j] then all elements to the right of i_th position(including it)
            // Will also be greater than A[j]. This is the crux.
            inv_count = inv_count + (mid-i+1); 
        }
        else // A[i]==A[j]
        {
            B[k]=A[i]; i++; k++;
            B[k]=A[j]; j++; k++;
        }
        
    }

    while(i<=mid)
    {
        B[k]=A[i]; k++; i++;
    }

    while(j<=high)
    {
        B[k]=A[j]; k++; j++;
    }

    // Copying all element from B to A.
    k=0; // again setting k=0;
    for(int i=low; i<=high; i++)
    {
        A[i]= B[k]; k++; // incrementing k after each element get copied
    }

    return inv_count;

}

int MergeSort(int* arr, int low, int high)
{   
    int inv_count=0;
    if(low<high)
    {
        int mid= (low+high)/2;
        inv_count += MergeSort(arr,low,mid);
        inv_count += MergeSort(arr,mid+1,high);
        inv_count += Merge(arr,low,mid,high);
    }
    return inv_count;
}

int main()
{
    int arr[]={5,2,4,3,1,7};
    int inv_count= MergeSort(arr,0,5);
    cout<<"Total inversion possible are "<<inv_count<<endl;
    for(int i=0; i<6; i++)
        cout<<arr[i]<<" ";
}

/*
Output:

Total inversion possible are 8
1 2 3 4 5 7
*/
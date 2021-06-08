#include<iostream>
#include<climits>
using namespace std;

int Kadane(int a[], int n)
{
    int max_sum=0, cur_sum=0;
    for(int i=0; i<n; i++)
    {
        cur_sum += a[i];
        if(cur_sum<0) { cur_sum=0; }
        max_sum = max(max_sum,cur_sum);
    }
    return max_sum;
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

    int non_wrap_maxsum= Kadane(a,n);
    int total_sum_array = 0;
    for(int i=0; i<n; i++) //Reversing the sign of elements
    {
       total_sum_array += a[i]; a[i] = -a[i]; 
    }
    int wrap_maxsum= total_sum_array + Kadane(a,n);
    int max_sum = max(non_wrap_maxsum, wrap_maxsum);
    cout<<"The max sum of subarray present in the given cyclic array is "<<max_sum<<endl;

}

/*
Output:

Enter the size of array: 7
4 -4 6 -6 10 -11 12
The max sum of subarray present in the given cyclic array is 22
*/
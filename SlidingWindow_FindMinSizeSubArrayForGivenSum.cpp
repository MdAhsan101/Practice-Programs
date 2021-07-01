#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<pair<int,int>> FindGivenSumSubArray(vector<int> v, int gs) // gs= given sum
{
    int n= v.size();
    int front=0, back=0;
    int cur_sum=v[0];
    vector<pair<int,int>> indexs;

    while(front<n && back<n)
    {
        while(front<n && cur_sum < gs)
        {   
            front++;
            cur_sum += v[front];
        }

        while(back<n && cur_sum > gs)
        {
            cur_sum -= v[back];
            back++;
        }

        if(cur_sum==gs)
        {
            indexs.push_back(make_pair(back,front));
            cur_sum -= v[back];
            back++;
        }
    }
    return indexs;  
}


int main()
{
    vector<int> arr={1,2,1,1,2,2,3,0,2};
    int sum=5;
    vector<pair<int,int>> indices= FindGivenSumSubArray(arr,sum);

    cout<<"Subarrays with sum=5 is : \n";
    int min_size=INT_MAX;
    for(auto index_pair: indices)
    {   
        min_size= min(min_size,(index_pair.second - index_pair.first + 1));
        for(int i=index_pair.first; i<=index_pair.second; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    cout<<"The min sized array found is of size : "<<min_size<<endl;
}

/*
Output:

Subarrays with sum=5 is : 
1 2 1 1
1 2 2
2 3
3 0 2
The min sized array found is of size : 2 
*/
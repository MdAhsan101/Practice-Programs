#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<pair<int,int>> AllSubArraysWithGivenSum(vector<int> &a, int gs) // gs= given sum
{
    int cum_sum=0;
    int n= a.size();
    map<int,int> mp;
    vector<pair<int,int>> sa_index;

    for(int i=0; i<n; i++)
    {
        cum_sum += a[i];
        mp[cum_sum]=i;
        
        if((cum_sum-gs)==0)
        {
            sa_index.push_back(make_pair(0,i));
        }

        auto itr= mp.find(cum_sum-gs);
        if(itr!=mp.end())
        {   
            int si= itr->second +1; 
            int ei= i;
            sa_index.push_back(make_pair(si,ei));            
        }        
    }
    return sa_index;
}

int main()
{
    vector<int> arr={10,15,-5,15,-10,5};
    int sum=20;
    
    vector<pair<int,int>> ans_idx= AllSubArraysWithGivenSum(arr,sum);
    for(auto idx: ans_idx)
    {
        for(int i=idx.first; i<=idx.second; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

/*
Output:
10 15 -5
15 -5 15 -10 5
*/

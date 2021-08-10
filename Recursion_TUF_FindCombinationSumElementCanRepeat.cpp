#include<bits/stdc++.h>
using namespace std;

void FindCombSum(int ind, int target, vector<int> &arr,vector<vector<int>> &ans, vector<int> &ds)
{
    if(ind==arr.size())
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if(arr[ind]<=target)
    {
        ds.push_back(arr[ind]);
        FindCombSum(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }

    FindCombSum(ind+1,target,arr,ans,ds);
}

vector<vector<int>> func(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    FindCombSum(0,target,arr,ans,ds);
    return ans;
}

int main()
{
    vector<int> arr={2,3,6,7};
    int target= 7;
    vector<vector<int>> ans= func(arr,target);
    for(auto v:ans)
    {
        for(auto ele:v)
            cout<<ele<<" ";
        cout<<endl;
    }   
}

/*
Output:
2 2 3 
7
*/
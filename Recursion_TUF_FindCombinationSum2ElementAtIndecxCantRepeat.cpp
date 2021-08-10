#include<bits/stdc++.h>
using namespace std;

void FindCombSum(int ind, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds)
{
    if(ind==arr.size())
    {
        if(target==0)
        {
            ans.insert(ds);
        }
        return;
    }

    if(arr[ind]<=target)
    {
        ds.push_back(arr[ind]);
        FindCombSum(ind+1,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }

    FindCombSum(ind+1,target,arr,ans,ds);
}

set<vector<int>> func(vector<int> &arr, int target)
{
    set<vector<int>> ans;
    vector<int> ds;
    FindCombSum(0,target,arr,ans,ds);
    return ans;
}

int main()
{
    vector<int> arr={10,1,2,7,6,1,5};
    int target= 8;
    set<vector<int>> ans= func(arr,target);
    for(auto v:ans)
    {
        for(auto ele:v)
            cout<<ele<<" ";
        cout<<endl;
    }   
}

/*
Output:
1 2 5 
1 6 1 
1 7   
2 1 5 
2 6   
7 1
*/
#include<bits/stdc++.h>
using namespace std;

void FindCombSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if(target==0)
        {ans.push_back(ds); return;}
    
    for(int i=ind; i<arr.size(); i++)
    {
        if(i>ind && (arr[i]==arr[i-1])) continue;
        if(arr[i]>target) break;

        ds.push_back(arr[i]);
        FindCombSum(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> func(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    FindCombSum(0,target,arr,ans,ds);
    return ans;
}

int main()
{
    vector<int> arr={10,1,2,7,6,1,5};
    int target= 8;
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
1 1 6 
1 2 5 
1 7   
2 6
*/
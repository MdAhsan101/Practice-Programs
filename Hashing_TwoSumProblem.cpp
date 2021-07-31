#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={1,3,2,6,4,11};
    int n= arr.size();
    unordered_map<int,int> hashmap;
    int target;
    cout<<"Enter the target sum : ";
    cin>>target;
    vector<pair<int,int>> ans;

    for(int i=0; i<n; i++)
    {
        auto itr= hashmap.find(target-arr[i]);
        if(itr!=hashmap.end())
        {
            ans.push_back({itr->first,i});
        }
        hashmap.insert({arr[i],i});
        //hashmap[arr[i]]=i;
    }

    for(auto pr: ans)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}

/*
Output:

Enter the target sum : 5
3 2
1 4
*/
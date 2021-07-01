#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> pr1, pair<int,int> pr2)
{
    return pr1.first>pr2.first;
}

void PrintTopKMostFreqElement(vector<int> &v,int k)
{
    map<int,int> mp;
    for(int i=0; i<v.size(); i++)
    {
        if(mp[v[i]]==0 && mp.size()==k+1)
            {
                break;
            }
        mp[v[i]]++; // by default map initialize key with zero;
    }

    // Strategy to sort map in desccending order as we can't directly sort it using sort()
    vector<pair<int,int>> ans;
    for(auto p: mp)
    {
        if(p.second!=0)
            ans.push_back(make_pair(p.first,p.second));
    }

    sort(ans.begin(),ans.end(),cmp);
    for(auto p: ans)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

}

int main()
{
    vector<int> arr={1,2,2,2,3,4};
    int k=2;
    PrintTopKMostFreqElement(arr,k);   
}

/*
Output:
2 3
1 1
*/
#include<iostream>
#include<vector>
using namespace std;

pair<int,int> FindSubArrSumDivBy3(vector<int> &v,int k)
{
    int n=v.size();
    int sum=0;
    pair<int,int> idxs;

    for(int i=0; i<k; i++)
    {
        sum+=v[i];
        
    }
    if(sum%3==0)
    {
        idxs=make_pair(0,k);
        return idxs;
    }

    int back=0, front=k; 
    while(front<n && back<n)
    {
        sum+= v[front++]-v[back++];
        if(sum%3==0)
        {
            idxs= make_pair(back,front);
            return idxs;
        }        
    }
    return make_pair(-1,0);
}

int main()
{
    vector<int> arr={1,2,2,3,1,2,5};
    int k= 3;
    pair<int,int> idx_ans= FindSubArrSumDivBy3(arr,k);
    if(idx_ans.first==-1)
    {
        cout<<"No such subarray found which is div by 3."<<endl;
    }
    else
    {
        for(int i=idx_ans.first; i<idx_ans.second; i++)
            cout<< arr[i]<<" ";
    }
    cout<<endl;
}
/*
Output:
2 3 1
*/

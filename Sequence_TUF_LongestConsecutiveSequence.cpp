#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={100,4,200,1,3,2};
    int n= arr.size();

    set<int> Set;
    for(auto ele:arr)
    {
        Set.insert(ele);
    }

    int cur_sqlen, max_sqlen=0;
    for(auto num:arr)
    {
        if(!Set.count(num-1))
        {
            cur_sqlen=1;
            int cur_num=num;
            while(Set.count(cur_num+1))
            {
                cur_sqlen++;
                cur_num++;
            }
            max_sqlen= max(cur_sqlen,max_sqlen);
        }
    }
    cout<<"The maximum sequence length thus found is "<<max_sqlen<<endl;
    // Output: The maximum sequence length thus found is 4
}
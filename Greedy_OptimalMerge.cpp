#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main()
{
    priority_queue<int,vector<int>, greater<int> > min_heap;
    int ans=0;

    vector<int> v={4,2,5,7};
    for(int i=0; i<v.size(); i++)
    {
        min_heap.push(v[i]);
    }

    while(min_heap.size()>1)
    {
        int e1= min_heap.top();
        min_heap.pop();
        int e2= min_heap.top();
        min_heap.pop();
        ans += (e1+e2);
        min_heap.push(e1+e2);
    }
    cout<<"Min operations possible while merging is "<<ans<<endl;
    // Output: Min operations possible while merging is 35
}
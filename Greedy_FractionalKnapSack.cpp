#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
struct data
{
    float val;
    float wt;
    float vpw; // value per weight
};

bool cmp(data d1, data d2)
{
    return d1.vpw>=d2.vpw;
}

int main()
{
    vector<int> value={60,100,120};
    vector<int> weight={10,20,30};
    float capacity=50;

    vector<data> d;
    for(int i=0; i<value.size(); i++)
    {
        data a;
        a.val= value[i];
        a.wt= weight[i];
        a.vpw= (a.val/a.wt);
        d.push_back(a);
    }

    // Sorting now in descending order according to vpw
    sort(d.begin(),d.end(),cmp);

    vector<data> ans;

    int i=0;
    while((i<d.size()) && (capacity>0))
    {
        if(capacity>=d[i].wt)
        {
            ans.push_back(d[i]);
            capacity -= d[i].wt;
        }
        else
        {
            data x;
            x.val= d[i].val;
            x.wt= capacity;
            capacity -= x.wt;
            x.vpw= d[i].vpw;
            ans.push_back(x);
        }
        i++;
    }
    cout<<"val wt val/wt"<<endl;
    for(auto ele: ans)
    {
        cout<<ele.val<<" "<<ele.wt<<" "<<ele.vpw<<endl;
    }    

}

/*
Output:

val wt val/wt
60 10 6
100 20 5
120 20 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct time_data
{
    int start;
    int finish;
    int mno; // meeting number
};

bool cmp(time_data td1, time_data td2)
{
    if(td1.finish==td2.finish)
        return td1.start<=td2.start;
    return td1.finish<td2.finish;
}

int main()
{
    vector<int> m_start={1,0,3,8,5,8};
    vector<int> m_finish={2,6,4,9,7,9};

    vector<time_data> td;
    for(int i=0; i<m_start.size(); i++)
    {
        time_data t;
        t.start= m_start[i];
        t.finish= m_finish[i];
        t.mno= i+1;
        td.push_back(t);
    }

    // Sorting in ascending order according to m_finish time
    sort(td.begin(), td.end(), cmp);
    vector<time_data> ans;
    int end_limit=0;

    for(int i=0; i<td.size(); i++)
    {
        if(td[i].start>end_limit)
        {
            ans.push_back(td[i]);
            end_limit= td[i].finish;
        }
    }

    for(auto ele: ans)
    {
        cout<<ele.mno<<" "<<ele.start<<" "<<ele.finish<<endl;
    }
}

/*
Output:

1 1 2
3 3 4
5 5 7
6 8 9
*/
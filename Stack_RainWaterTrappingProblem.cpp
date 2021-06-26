#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

vector<int> arr{3,5,2,4,6,1,2};
vector<int> left_max_val;
vector<int> rt_max_val;

void MaxVal_To_Left()
{
    stack<int> s;
    int n= arr.size();
    for(int i=0; i<n; i++)
    {
        if(s.empty())
            {
                left_max_val.push_back(-1);
                s.push(arr[i]);
            }
        else if(s.top() > arr[i])
            left_max_val.push_back(s.top());
        else if(s.top() < arr[i])
            {
                left_max_val.push_back(-1);
                s.push(arr[i]);
            }
        //cout<<i<<endl;
    }
}

void MaxVal_To_Right()
{
    stack<int> s;
    int n= arr.size();
    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
            {
                rt_max_val.push_back(-1);
                s.push(arr[i]);
            }
        else if(s.top() > arr[i])
            rt_max_val.push_back(s.top());
        else if(s.top() <= arr[i])
            {
                rt_max_val.push_back(-1);
                s.push(arr[i]);
            }
    }
    reverse(rt_max_val.begin(),rt_max_val.end());
}

int RainWaterSum()
{
    int water_sum=0;
    int n= arr.size();
    MaxVal_To_Left();
    MaxVal_To_Right();
    for(int i=0; i<n; i++)
    {
        if(left_max_val[i]>=0 && rt_max_val[i]>=0)
        {
            int m= min(left_max_val[i],rt_max_val[i]);
            water_sum += (m-arr[i]); 
        }
    }
    return water_sum;
}


int main()
{
    int ans = RainWaterSum();
    for(int i=0; i<arr.size(); i++)
        cout<<left_max_val[i]<<" ";
    cout<<endl; // -1 -1 5 5 -1 6 6

    for(int i=0; i<arr.size(); i++)
        cout<<rt_max_val[i]<<" ";
    cout<<endl; // 6 6 6 6 -1 2 -1

    cout<<"Total water trapped is "<<ans<<endl; 
    // Total water trapped is 5
}

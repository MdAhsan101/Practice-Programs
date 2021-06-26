#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> price{3,5,4,2,6,4};
vector<int> gvil_arr; // greater value index on left side array
vector<int> span_arr;

void Near_GreaterValue_Index_OnLeft()
{
    int n= price.size();
    stack<int> stk;

    for(int i=0; i<n; i++)
    {
        if(stk.empty())
        {
            gvil_arr.push_back(-1);
            stk.push(i);
        }
        else if(price[stk.top()]>price[i])
        {
            gvil_arr.push_back(stk.top());
            stk.push(i);                        
        }
        else if(price[stk.top()]<=price[i])
        {
            while(!stk.empty() && (price[stk.top()]<=price[i]))
            {
                stk.pop();
            }
            if(stk.empty())
                gvil_arr.push_back(-1);
            else
            {
            gvil_arr.push_back(stk.top());
            }
            stk.push(i);
        }
    }
    for(int i=0; i<price.size(); i++)
    {
        cout<<gvil_arr[i]<<" ";
    }
    cout<<endl;
    // -1 -1 1 2 -1 4
}

void Stock_Span_Calc()
{
    Near_GreaterValue_Index_OnLeft();
    int n= price.size();

    for(int i=0; i<n; i++)
    {
        span_arr.push_back(i-gvil_arr[i]);
    }
}

int main()
{
    Stock_Span_Calc();
    cout<<"My calculated Span Array is : ";
    for(int i=0; i<price.size(); i++)
    {
        cout<<span_arr[i]<<" ";
    }
    cout<<endl;
    // My calculated Span Array is : 1 2 1 1 5 1

}
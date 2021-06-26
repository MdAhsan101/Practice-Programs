#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> nsli_arr;
vector<int> nsri_arr;

void Nearest_SmallerValue_Left_Index(vector<int> &arr)
{
    stack<int> s;
    int n= arr.size();
    for(int i=0; i<n; i++)
    {
        if(s.empty())
        {
            nsli_arr.push_back(-1);
        }
        else if(arr[s.top()]<arr[i])
        {
            nsli_arr.push_back(s.top());
        }
        else if(arr[s.top()]>=arr[i])
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nsli_arr.push_back(-1);
            }
            else
            {
                nsli_arr.push_back(s.top());
            }
        }
        s.push(i);
    }
    cout<<"Nearest_SmallestValue_Left_Index_Array is ";
    for(auto ele: nsli_arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

void Nearest_SmallerValue_Right_Index(vector<int> &arr)
{
    stack<int> s2;
    int n= arr.size();
    for(int i=n-1; i>=0; i--)
    {
        if(s2.empty())
        {
            nsri_arr.push_back(n);
        }
        else if(arr[s2.top()]<arr[i])
        {
            nsri_arr.push_back(s2.top());
        }
        else if(arr[s2.top()]>=arr[i])
        {
            while(!s2.empty() && arr[s2.top()]>=arr[i])
            {
                s2.pop();
            }
            if(s2.empty())
            {
                nsri_arr.push_back(n);
            }
            else
            {
                nsri_arr.push_back(s2.top());
            }
        }
        s2.push(i);
    }
    reverse(nsri_arr.begin(),nsri_arr.end());
    cout<<"Nearest_SmallestValue_Right_Index_Array is ";
    for(auto ele: nsri_arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int Max_Area_Rectangle(vector<int> &arr)
{
    int max_area=-32767;
    int nsli, nsri;
    
    Nearest_SmallerValue_Left_Index(arr);
    Nearest_SmallerValue_Right_Index(arr);
    
    int n= arr.size();
    int area_arr[n];
    
    for(int i=0; i<n; i++)
    {
        area_arr[i]= arr[i]*(nsri_arr[i]-nsli_arr[i]-1);
        max_area= max(area_arr[i], max_area);
    }
    return max_area;
}

int main()
{
    vector<int> arr{3,5,4,2,6,4};
    int max_area= Max_Area_Rectangle(arr);
    cout<<"The maximum area found is "<<max_area<<endl;    
}

/*
Output:

Nearest_SmallestValue_Left_Index_Array is -1 0 0 -1 3 3 
Nearest_SmallestValue_Right_Index_Array is 3 2 3 6 5 6
The maximum area found is 12

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={4,3,3,4,4,2,1,2,1,1};
    sort(arr.begin(),arr.end());  // 1,1,1,2,2,3,3,4,4,4

    vector<vector<int>> ans;

    int target;
    cout<<"Enter the target value for 4 sum: ";
    cin>>target;
    int n= arr.size();

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int target2= target-arr[i]-arr[j];
            int front=j+1, back=n-1;
            while(front<back)
            {
                if(target2 < (arr[front]+arr[back]))
                    front++;
                else if(target2 > (arr[front]+arr[back]))
                    back--;
                else
                {
                    vector<int> v(4);
                    v[0]=arr[i];
                    v[1]=arr[j];
                    v[2]=arr[front];
                    v[3]=arr[back];
                    
                    ans.push_back(v);
                    while(front<back  &&  arr[front]==v[2]) ++front;
                    while(front<back  &&  arr[back]==v[3]) --back;
                }               
            }
            while(j+1<n && arr[j+1]==arr[j]) ++j;
        }
        while(i+1<n && arr[i+1]==arr[i]) ++i;
        
    }

    cout<<"All possible 4 element combinations found in array are:\n";
    for(auto v:ans)
    {
        cout<<v[0]<<","<<v[1]<<","<<v[2]<<","<<v[3]<<endl;
    }
}

/*
Output:

Enter the target value for 4 sum: 9
All possible 4 element combinations found in array are:
1,2,2,4
1,2,3,3
*/
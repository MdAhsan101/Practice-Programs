#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool IsPalindrome(int input_num)
{
    int rev_num=0;
    int saved_num= input_num;

    // Reversing the given number
    while(input_num!=0)
    {
        rev_num= (rev_num*10)+(input_num%10);
        input_num= input_num/10;        
    }
        
    if(saved_num==rev_num)
        return true;
    return false;
}

// Function to find all possible palindromic number possible from k size subarray
vector<pair<int,int>> FindAllPalindromicSubArray(vector<int> &v, int k)
{
    int num=0;
    vector<pair<int,int>> idxs;
    for(int i=0; i<k; i++)
    {
        num= (num*10)+v[i];
    }
    
    if(IsPalindrome(num))
    {
        pair<int,int> p= make_pair(0,k-1);
        idxs.push_back(p);
    }

    for(int i=k; i<v.size(); i++)
    {
        num= (num % (int)pow(10,k-1))*10 + v[i];
    
        if(IsPalindrome(num))
        {
            pair<int,int> p= make_pair(i-k+1,i);
            idxs.push_back(p);
        }
    }
    return idxs;        
}


int main()
{
    vector<int> arr{1,1,2,1,2,2,1,0,0,1,5};
    int k=4;

    vector<pair<int,int>> idx_ans= FindAllPalindromicSubArray(arr,k);
    
    for(auto p: idx_ans)
    {
        for(int i=p.first; i<=p.second; i++)
        {
            cout<<arr[i]<<"";
        }
        cout<<endl;
    }
}

/*
Output:
1221
1001
*/
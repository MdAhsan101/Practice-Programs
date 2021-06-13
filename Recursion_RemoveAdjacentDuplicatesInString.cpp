#include<iostream>
using namespace std;

string remove_adj_dup(string s)
{
    if(s.length()==0)
        return "";
    char c= s[0];
    string ros= s.substr(1);
    string ans= remove_adj_dup(ros);
    if(c==ans[0])
    {
        return ans;
    }
    else
    {
        return c+ans;
    }
}

int main()
{
    string str= "abbcddefeeg";
    cout<<remove_adj_dup(str); // abcdefeg
}
#include<iostream>
using namespace std;

string MoveAllxToEnd(string s)
{
    if(s.length()==0)
        return "";
    char c=s[0];
    string ros= s.substr(1);
    string ans= MoveAllxToEnd(ros);

    if(c=='x')
    {
        return ans+c;
    }
    else
    {
        return c+ans;
    }
}
int main()
{
    string str="sdfxxfghixlpxc";
    cout<<MoveAllxToEnd(str);  // sdffghilpcxxxx
}
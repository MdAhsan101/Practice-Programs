#include<iostream>
using namespace std;

void ReplacePi(string s,int n)
{
    if(s.length()==0)
        return ;
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        string ros= s.substr(2);
        ReplacePi(ros,n);
    }
    else
    {
        cout<<s[0];
        string ros= s.substr(1);
        ReplacePi(ros,n);
    }
}

int main()
{
    string str="ppiipippip";
    ReplacePi(str,str.length()); // p3.14i3.14p3.14p
}
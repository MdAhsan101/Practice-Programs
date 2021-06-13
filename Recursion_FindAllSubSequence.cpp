#include<iostream>
using namespace std;

void FindAllSubSeq(string s, string ans)
{
    if(s.length()==0)
        {
            cout<<ans<<endl;
            return ;
        }
    char c= s[0];
    string ros= s.substr(1);
    FindAllSubSeq(ros,ans);
    FindAllSubSeq(ros,ans+c); 
}

int main()
{
    string str= "ABC";
    FindAllSubSeq(str,"");
}

/*
Output:


C 
B 
BC
A 
AC
AB
ABC
*/
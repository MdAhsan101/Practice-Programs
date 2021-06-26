#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int CheckRedundantParenthesis(string s)
{
    stack<int> stk;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')')
        {
            int flag=0;
            // checking whether any operator is present in btwee parenthesis
            while(!stk.empty() && stk.top()!='(') 
            {
                stk.pop();
                flag=1;
            }
            stk.pop();
            if(flag==0)
                return true;
        }
    }
    return false;
}

int main()
{
    string s= "(a+((b-c)))";
    bool ans= CheckRedundantParenthesis(s);
    cout<<ans<<endl;  // 1

    s= "(a+(b-c))";
    ans= CheckRedundantParenthesis(s);
    cout<<ans; // 0
}
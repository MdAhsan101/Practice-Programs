#include<iostream>
using namespace std;

int DecimalToBinary(int n)
{
    int x=1;
    while(x<=n)
        x= x*2;
    x=x/2;

    int ans=0;
    while(x>0)
    {
        int q= n/x;
        ans = ans*10 + q;
        n -= q*x;
        x= x/2;
    }
    return ans;
}

int BinaryToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int lastdigit= n%10;
        n= n/10;
        ans += x*lastdigit;
        x = x*2;
    }
    return ans;
}

int DecimalToOctal(int n)
{
    int x=1;
    while(x<=n)
        x= x*8;
    x=x/8;

    int ans=0;
    while(x>0)
    {
        int q= n/x;
        ans = ans*10 + q;
        n -= q*x;
        x= x/8;
    }
    return ans;
}

int OctalToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int lastdigit= n%10;
        n= n/10;
        ans += x*lastdigit;
        x = x*8;
    }
    return ans;
}

string DecimalToHexaDecimal(int n)
{
    int x=1;
    while(x<=n)
    {
        x=x*16;
    }
    x= x/16;

    string ans="";
    while(x>0)
    {
        int q= n/x;
        if(q<=9)
        {
            ans= ans+to_string(q);
        }
        else
        {
            char c= 'A'+q-10;
            ans.push_back(c);
        }
        x= x/16;
    }
    return ans;
}

int HexaDecimalToDecimal(string n)
{
    int s= n.size();
    int x=1;
    int ans=0;
    for(int i=s-1; i>=0; i--)
    {   
        char c= n[i];
        if(c>='0' && c<='9')
        {
            int m= c-'0';
            cout<<m<<"\n";
            ans= ans+ x*m;
            cout<<"Step Ans1="<<ans<<endl;
        }
        else
        {
            int m=10+(c-'A');
            cout<<m<<"\n";
            ans= ans + x*m;
            cout<<"Step Ans2="<<ans<<endl;
        }      
        x= x*16;
    }
    return ans;
}


int main()
{
    cout<<"Enter decimal no. : ";
    int n;
    cin>>n;

    cout<<"Binary form of  given no. is "<<DecimalToBinary(n);

    cout<<"\nOctal form of  given no. is "<<DecimalToOctal(n);

    cout<<"\nHexaDeciaml form of  given no. is "<<DecimalToHexaDecimal(n);

    cout<<"\n\nEnter no. in binary format: ";
    cin>>n;
    cout<<"Decimal form of  given no. is "<<BinaryToDecimal(n);

    cout<<"\n\nEnter no. in Octal format: ";
    cin>>n;
    cout<<"Decimal form of  given no. is "<<OctalToDecimal(n);

    cout<<"\n\nEnter no. in HexaDecimal format: ";
    string s;
    cin>>s;
    cout<<"Decimal form of  given no. is "<<HexaDecimalToDecimal(s);
    return 0;
}
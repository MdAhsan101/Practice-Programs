#include<iostream>
using namespace std;

int getbit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}

int setbit(int n,int pos)
{
    return (n | (1<<pos));
}

int clearbit(int n, int pos)
{
    int mask= ~(1<<pos);
    return (n & mask);
}

int updatebit(int n, int pos, int val) // clearbit+setvaluebit
{
    int mask= ~(1<<pos);
    n= (n & mask);
    return (n | (val<<pos));
}

int CheckPowerOfTWO(int n)
{
    return ( !(n & (n-1)) && (n)); 
}

int Count_1_In_BinaryFormat_Of_Number (int n)
{
    int count=0;
    while(n)
    {
        n= n & (n-1);
        count++;
    }
    return count;
}


int main()
{
    cout<<getbit(2,1)<<" "<<getbit(2,2)<<endl;; //2= 0010
    cout<<setbit(2,0)<<endl; // 2= 0010 -> 0011=3
    cout<<clearbit(5,2)<<endl; // 5=0101 -> 0001=1
    cout<<updatebit(5,1,1)<<endl; // 5=0101 -> 0111 = 7
    cout<<CheckPowerOfTWO(16)<<endl; // 16=10000 -> (10000 & 01111)=(00000)=0 ->!0 = 1=TRUE
}
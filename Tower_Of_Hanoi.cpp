#include<iostream>
using namespace std;

void TOH(int n,char src, char dest, char helper)
{
    if(n==0) return ;

    TOH(n-1,src,helper,dest);
    cout<<"Moved "<<src<<" to "<<dest<<endl;
    TOH(n-1,helper,dest,src);
}

int main()
{
    TOH(3,'A','C','B');
}

/*
Output:

Moved A to C
Moved A to B
Moved C to B
Moved A to C
Moved B to A
Moved B to C
Moved A to C
*/
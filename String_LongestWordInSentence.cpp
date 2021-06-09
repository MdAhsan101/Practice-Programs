#include<iostream>
#include<string>
#include<climits>
using namespace std;

int main()
{
    cout<<"Enter your sentance here: ";
    string carr;
    getline(cin,carr);
    
    int i=0, csi=0,  cur_len=0, max_si=0;
    int max_len= INT16_MIN;

    while(carr[i] != '\0')
    {
        if(carr[i]==' ')
        { cur_len=0; csi= i+1;}
        else
        {
            cur_len ++;
            if(max_len<cur_len)
            {
                max_len=cur_len;
                max_si= csi;
            }
        }
        i++;
    }
    cout<<"The max length word found is ";
    for(int i=max_si; i<=(max_si+max_len); i++)
        cout<<carr[i];
    cout<<" and max length is "<<max_len;
    return 0;
}
/*
Output:
Enter your sentance here: Hello Shubham How are you

The max length word found is Shubham  and max length is 7
*/


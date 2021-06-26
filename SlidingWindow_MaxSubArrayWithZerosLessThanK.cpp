#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str="110111011010110111110";
    int k=2; // max two 0's are allowed in a substring
    int i=0, j=0;
    int max_len= -1, max_i, max_j;
    int n= str.length();

    int zc=0;
    while(j<n)    
    {
        if(str[j]=='0')
            {zc++;}
        
        if(zc>k)
        {
            int cur_len= j-i;
            max_i=i;
            max_j=j;
            max_len= max(max_len, cur_len);

            while(zc>k)
            {
                if(str[i]=='0')
                    zc--;
                i++;
                //cout<<i<<endl;
            }
            cur_len=0;
        }
        if(j==n-1)
        {
            int cur_len= j-i+1;
            max_len= max(max_len, cur_len);
        }
        j++;
        //cout<<j<<endl;
    }

    cout<<"MaxLen substring with "<<k<<" zeroes is "<<max_len<<" from index "<<max_i<<" to "<<max_j<<endl;
    // Output: MaxLen substring with 2 zeroes is 10 from index 10 to 20
}
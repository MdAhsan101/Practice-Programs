#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<char,int> mp;
    int i=0, j=0,  max_len=-32767;
    int total=0, count=0;
    string str="abbacbcdbadbdbbdcb";
    int n= str.length();
    //cout<<n;

    while(j<n && i<n)
    {
        mp[str[j]]++;

        if((j<n) && (mp.size()==j-i+1))
        {            
            if(mp[str[j]]==1)
                max_len = max(max_len, j-i+1);
            j++;
            
        }
        
        else if( i<n && (mp.size()< (j-i+1)))
        {   
            mp[str[i]]--;
            if(mp[str[i]]==0)
            {
                mp.erase(str[i]);
            }
            i++;
        }
    }

    cout<<"MaxLen SubArray with Unique Characters is "<<max_len<<endl;
    // Output: MaxLen SubArray with Unique Characters is 4
    
}
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int freq[26];
    for(int i=0; i<26; i++)
        freq[i]=0;
    
    string str;
    getline(cin,str);

    for(int i=0; i<str.size();i++ )
    {
        if((str[i]>='a')&&(str[i]<='z'))
        {
            freq[str[i]-'a']++;
        }
        else if((str[i]>='A')&&(str[i]<='Z'))
        {
            freq[str[i]-'A']++;
        }
    }
    int max_freq= INT16_MIN;
    int max_index= 0;
    for(int i=0; i<=25; i++)
    {
        if(freq[i]>max_freq)
        {
            max_freq=freq[i];
            max_index=i;
        }
    }
    char c= 'a'+max_index;
    cout<<"Max Freq charecter is "<< c <<" and freq value is "<<max_freq<<endl;
    return 0;
}

/*
Output:

Hello World
Max Freq charecter is l and freq value is 3
*/
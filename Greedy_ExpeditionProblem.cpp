#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int l,p;
    cout<<"Enter the initial distance from town and fuel respectively for the truck: ";
    cin>>l>>p;
    int n;
    cout<<"Enter the no. of stops available: ";
    cin>>n;
    int i=0;
    vector<pair<int,int>> v;
    while(i<n)
    {   
        pair<int,int> x;
        cout<<"Enter distance from truck for stop "<<i+1<<": ";
        cin>>x.first;
        cout<<"Enter fuel available at stop "<<i+1<<": ";
        cin>>x.second;
        v.push_back(x);
        i++;
    }
    //sorting in ascending oreder according to distance from truck i.e pair.first
    sort(v.begin(),v.end()); // by default sorting happens in ascending order acc. to key

    int fuel=p, dc=0; //distance_covered;
    int cnt=0; // counting stopping points for refilling fuel
    int dist= v[0].first;
    int flag=0;

    for(int i=0; i<n; i++)
    {
        while(fuel>=dist)
        {   
            dc= v[i].first;
            fuel -= dist;
            if(i==n-1)
                dist= l-dc;
            else
                dist= v[i+1].first-dc;
            cout<<i<<" "<<dc<<" "<<fuel<<" "<<dist<<endl;
            i++;
        }
        i--;

        if(i!=-1)
        {
            fuel += v[i].second;
            cout<<i<<" "<<dc<<" "<<fuel<<" "<<dist<<endl;
            cnt++;
        }
        else
        {
            flag=1; break;
        }
    }

    cout<<i<<" "<<dc<<" "<<fuel<<" "<<dist<<endl;
    if((l-dc)>fuel)
        flag=1;
    
    if(flag==1)
        cout<<"Destination can't be reached"<<endl;
    else
        cout<<"Destination can be reached with min of "<<cnt<<" stops"<<endl;

}

/*
Output:
Enter the initial distance from town and fuel respectively for the truck: 25 10
Enter the no. of stops available: 4
Enter distance from truck for stop 1: 21
Enter fuel available at stop 1: 4
Enter distance from truck for stop 2: 20
Enter fuel available at stop 2: 2
Enter distance from truck for stop 3: 14
Enter fuel available at stop 3: 5
Enter distance from truck for stop 4: 10
Enter fuel available at stop 4: 10
0 10 0 4
0 10 10 4
1 14 6 6
2 20 0 1
2 20 2 1
3 21 1 4
3 21 5 4
4 21 5 4
Destination can be reached with min of 3 stops
*/
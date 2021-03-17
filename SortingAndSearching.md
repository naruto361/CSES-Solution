## [MOVIE FESTIVAL](https://cses.fi/problemset/task/1629)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
int main()
{
    vector<pair<int,int>> v;
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),sortbysec);
    int ans=1;
    int end=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first>=end)
        {
            ans++;
            end=v[i].second;
        }
    }
    cout<<ans;
    return 0;
}
```

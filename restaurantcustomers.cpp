#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans=0;
    vector<pair<int,int>> v;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }
    sort(v.begin(),v.end());
    int maxi=0;
    for(auto i:v)
    {
        ans+=i.second;
        maxi=max(maxi,ans);
    }
    cout<<maxi;
}

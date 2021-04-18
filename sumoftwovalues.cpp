#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({a[i],i});
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    while(i<j)
    {
        if(v[i].first + v[j].first>m) j--;
        else if(v[i].first +v[j].first<m) i++;
        else{
            cout<<v[i].second+1<<" "<<v[j].second+1;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}
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
## [SUM OF THREE VALUES](https://cses.fi/problemset/task/1641/)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    int pp=0;
    if(n>=3){
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back(make_pair(a[i],i+1));
    sort(v.begin(),v.end());
    //for(auto r:v) cout<<r.first<<" "<<r.second<<endl;
    for(int i=0;i<v.size();i++)
    {
        int stop=0;
        int j=0,k=v.size()-1;
        while(j<k)
        {
            
            if(v[i].first +v[j].first+v[k].first==m &&(i!=j && i!=k)) 
            {
                ll q[3];
                q[0]=v[i].second;q[1]=v[j].second;q[2]=v[k].second;
                sort(q,q+3);
                for( int y:q) cout<<y<<" ";
                stop=1;pp=1;break;
            }
            else if(v[i].first +v[j].first+v[k].first<m) j++;
            else k--;
        }
        if(stop) break;
    }
    }
    if(pp==0 || n<3) cout<<"IMPOSSIBLE";

    
} 
```

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
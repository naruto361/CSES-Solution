#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<bool>> vis;
vector<vector<int>> dist;
queue<pair<int,int>> q;
vector<vector<int>> path;
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
vector<char> dir={'U','D','L','R'};
int ax,ay,bx,by;
bool valid(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return 0;
    return 1;
}
void bfs()
{
    q.push({ax,ay});
    vis[ax][ay]=1;
    while(!q.empty())
    {
        int k1=q.front().first,k2=q.front().second;
        vis[k1][k2]=1;
        //if(k1==bx && k2==by) return;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=k1+dx[i],ny=k2+dy[i];
            if(valid(nx,ny))
            {
                q.push({nx,ny});
                dist[nx][ny]=1+dist[k1][k2];
                vis[nx][ny]=1;
                path[nx][ny]=i;
                //if(nx==bx && ny==by) 
            }
        }
    }
}
int main()
{
    cin>>n>>m;vis.resize(n);
    dist.resize(n);path.resize(n);
    for(int i=0;i<n;i++) vis[i].resize(m),dist[i].resize(m),path[i].resize(m);
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int j=0;j<s.length();j++)
            if(s[j]=='A') ax=i,ay=j;
            else if(s[j]=='B') bx=i,by=j;
            else if(s[j]=='#') vis[i][j]=1;
        
    }
    bfs();
    if(vis[bx][by]==0) cout<<"NO";
    else{
        cout<<"YES\n";
        int d=dist[bx][by];
        cout<<dist[bx][by]<<"\n";
        string t="";
        while(1)
        {
            int p=path[bx][by];
            t+=dir[p];
            bx-=dx[p];
            by-=dy[p];
            if(bx==ax && by==ay) break;
        }
        reverse(t.begin(),t.end());
        cout<<t;
    }
}
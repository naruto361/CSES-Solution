#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int>> v(100001);
int vis[100001];
int size[100001];
int dist[100001];
vector<int> par;
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    dist[node]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int child:v[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                dist[child]=dist[curr]+1;
                par[child]=curr;
                vis[child]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
        int vertex,edges;
        cin>>vertex>>edges;
        par.resize(vertex+1,-1);
        for(int i=1;i<=vertex;i++) v[i].clear(),dist[i]=0,vis[i]=0;
        for(int i=1;i<=edges;i++)
        {
            int x,y;cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        bfs(1);
        //cout<<dist[vertex]<<endl;
        if(par[vertex]==-1) cout<<"IMPOSSIBLE";
        else
        {
            stack<int> st;
            while(vertex!=-1)
            {
                st.push(vertex);
                vertex=par[vertex];
            }
            cout<<st.size()<<endl;
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        return 0;
}
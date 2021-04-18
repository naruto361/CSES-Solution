#include <bits/stdc++.h>
using namespace std;
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define ll long long int
#define pb push_back
#define mod 1000000007
#define nl cout<<"\n";
#define loop1(m) for(int i=0;i<m;i++) 
#define loop2(n,m) for(auto i=n;i<=m;i++)
#define count1s(n) __builtin_popcount(n)
bool psqrt(ll x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
}
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
bool isprime(ll n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
}
int countdigits(ll n)
{
	return floor(log10(n)+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    int s;cin>>s;
    if(s==0) fill(dp[0].begin(),dp[0].end(),1);
    else dp[0][s]=1;
    for(int i=1;i<n;i++)
    {
        int x;cin>>x;
        if(x==0)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=j-1;k<=j+1;k++)
                {
                    if(k>=1 && k<=m)
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        else
        {
            for(int k=x-1;k<=x+1;k++)
            {
                if(k>=1 && k<=m)
                {
                    dp[i][x]=(dp[i][x]+dp[i-1][k])%mod;
                }
            }
        }

    }
    int sum=0;
    for(int j=1;j<=m;j++) sum=(sum+dp[n-1][j])%mod;
    cout<<sum;
}
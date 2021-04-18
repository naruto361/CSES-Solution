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
    int n;cin>>n;
    int target=(n*(n+1))/2;
    if(target&1)
    {
        cout<<0;
        return 0;
    }
    target/=2;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=i)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-i])%mod;
            }
        }
    }
    cout<<dp[n-1][target];
}
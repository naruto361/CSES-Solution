## [Subarray Sums I](https://cses.fi/problemset/task/1660/)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int subarraySum(int a[],int n, int k) {
        ll sum=0;
        unordered_map<ll,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(mp.find(sum-k)!=mp.end()) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<subarraySum(a,n,m);
} 
```

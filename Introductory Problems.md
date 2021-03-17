## [APPLE DIVISION](https://cses.fi/problemset/task/1068)

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    ll ans=INT_MAX;
    for(int i=0;i<1<<n;i++)
    {
        ll k=0;
        for(int j=0;j<n;j++)
        {
            if((i & 1<<j )!=0)
            {
                k+=a[j];
            }
        }
        //if(k!=sum)
        ans=min(ans,abs((sum-k)-k));
    }
    cout<<ans;
}
```
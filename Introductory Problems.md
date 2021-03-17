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

## [COIN PILES](https://cses.fi/problemset/task/1754)

```cpp
#include<bits/stdc++.h>
using namespace std;
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(b>a) swap(a,b);

        if(a==2*b) YES
        else if(a>2*b) NO
        else if((a+b) %3==0) YES
        else NO
        
    }
    return 0;
}
```


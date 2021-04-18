#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll ans=0;
    if(n&1)
    {
        int k=(n-1)/2;
        for(int i=0;i<n;i++)
        ans+=abs(a[i]-a[k]);
    }
    else{
        int k=0;
        if(a[n/2-1]-a[0]<=a[n-1]-a[n/2]) k=a[n/2-1];
        else k=a[n/2];
        for(int i=0;i<n;i++) ans+=abs(a[i]-k);
    }
    cout<<ans;
    return 0;
 
}
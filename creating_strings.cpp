#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<string> v;
    sort(s.begin(),s.end());
    v.push_back(s);
    while(next_permutation(s.begin(),s.end()))
    {
        v.push_back(s);
    }
    cout<<v.size()<<"\n";
    for(auto i:v) cout<<i<<"\n";
}
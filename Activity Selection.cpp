#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());

    int sesh=-1,ans=0;
    for(int i=0; i<n; i++)
    {
        if(sesh<=v[i].second)
        {
            ans++;
            sesh=v[i].first;
        }
    }

    cout<<ans<<endl;
}
/// time complexity : o(n)

/*
10
1 3 2 4 8 7 9 11 9 12
3 4 5 7 9 10 11 12 13 14
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll,ll>x,pair<ll,ll>y)
{
    return ((double)x.first/x.second)>((double)y.first/y.second);
}
int main()
{
    ll n,box;
    cin >> n >> box;
    vector<ll>w(n),p(n);
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }

    vector<pair<ll,ll>>r;
    for(int i=0 ; i<n; i++)
    {
        r.push_back({p[i],w[i]});
    }

    sort(r.begin(),r.end(),cmp);
    double res = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(r[i].second<=box)
        {
            res+=r[i].first;
            box-=r[i].second;
        }
        else
        {
            res+=((double)r[i].first/r[i].second)*box;
            break;
        }
    }

    cout << fixed << setprecision(10) << res;
}
///time complexity : O(nlogn)
/*
6 60
20 30 40 25 35 15
70 110 130 85 100 60
*/
v

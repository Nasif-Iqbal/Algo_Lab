#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int inf =1e9+10;

vector<vector<pair<ll,ll>>>adj(1000);
vector<bool>vis(1000,false);
vector<ll>dis(1000,inf);

void d(int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>p;

    p.push({0,n});
    dis[n]=0;
    while(p.empty()==false)
    {
        ll s = p.top().second;
        ll d = p.top().first;
        p.pop();
        if(vis[s]) continue;
        vis[s]=true;
        for(auto i : adj[s])
        {
            ll dd = i.first;
            ll x  = i.second;

            if(dd+d<dis[x])
            {
                p.push({(dd+d),x});
                dis[x]=dd+d;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin >> n >> e;
    for(int i=0 ; i<e ; i++)
    {
        ll x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    d(0);
    for(int i=0 ; i<n ; i++)
    {
        cout << "distance from 0 to " << i << " : " << dis[i] << endl;
    }
}

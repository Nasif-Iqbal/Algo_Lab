#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj(1000);
vector<bool>vis(1000);
int prims(int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,n});
    int total = 0;
    while(!pq.empty())
    {
        int s= pq.top().second;
        int dis= pq.top().first;
        pq.pop();
        if(vis[s]) continue;
        vis[s]=1;
        total+=dis;
        for(auto u : adj[s])
        {
            if(vis[u.second]!=1)
            {
                pq.push({u.first,u.second});
            }
        }
    }
    return total;
}

int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0 ; i<e ; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    int node;
    cin >> node;
    cout << prims(node);
}
/// time complexity : O((V+E)log(v))
/*
input:
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0

output:
7
*/

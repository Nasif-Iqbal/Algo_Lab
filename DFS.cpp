#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
vector<int>vis(1000);

void dfs(int n)
{
    int s=n;
    vis[s]=1;
    cout<<s<<"->";
    for(auto u:adj[s])
    {
        if(vis[u]!=1)
        {
            dfs(u);
        }
    }
}

int main()
{

    int v,e;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(4);

    return 0;
}

///time complexity : O(v+E)
/*
5 6
0 1
0 2
1 2
1 3
3 4
2 4

ans= 4->3->1->0->2
*/

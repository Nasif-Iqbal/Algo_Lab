#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
vector<int>vis(1000);

void bfs(int n)
{
    int s=n;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        cout<<q.front()<<"->";
        s=q.front();
        q.pop();
        for(auto u:adj[s])
        {
            if(vis[u]!=1)
            {
                q.push(u);
                vis[u]=1;
            }
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
    bfs(4);

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

ans= 4->3->2->1->0
*/

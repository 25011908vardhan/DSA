//TC-> O(N+E)
//SC-> adjlist->O(N+E)+ visArr->O(N)+ queue->O(N)
#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>>&adj,int start,int n)
{
    queue<int>q;
    q.push(start);
    vector<int>vis(n,0);
    vector<int>bfsAns;
    vis[start]=1;
    while(!q.empty())
    {
        int node=q.front();
        bfsAns.push_back(node);
        q.pop();
        for(auto &it:adj[node])
        if(!vis[it])
        {
            vis[it]=1;
            q.push(it);
        }
    }
    return bfsAns;
}
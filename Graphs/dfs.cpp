#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC-> O(N+E)
//SC-> O(N+E) (adjList) + O(N) (visited) + O(N) (aux space)
void dfs(int start,vector<int>&vis,vector<vector<int>>&adj)
{
    vis[start]=1;
    for(auto &it:adj[start])
    if(!vis[it])
    dfs(it,vis,adj);
}
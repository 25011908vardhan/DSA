#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC-> O(N+E)
//SC-> O(N+E) (adjList) + O(N) (visited) + O(N) (queue)
bool bfs(vector<vector<int>>&adj,vector<int>&vis)
{
    queue<pair<int,int>>q;//{node,parent}
    q.push({0,-1});
    vis[0]=1;
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto &it:adj[node])
        {
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else{
                if(it!=parent)return true;
            }
        }
    }
    return false;
    
}
//SC-> O(N+E) (adjList) + O(N) (visited) + O(N) (aux space)
bool dfs(int start,vector<vector<int>>&adj,vector<int>&vis,int parent)
{
    vis[start]=1;
    for(auto &it:adj[start])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,vis,start))return true;
        }
        else{
            if(it!=parent)return true;
        }
    }
    return false;
}
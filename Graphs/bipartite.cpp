#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC-> O(N+E)
//SC-> O(N+E) (adjList) + O(N) (visited) + O(N) (queue)
//Pass parentColor while calling always either 1 or 0 to start with...Graph is bipartite if it can be colored with 2 distinct colors exactly, thus no cycles of odd length should be present...
bool bipartiteDFS(vector<vector<int>>&adj,vector<int>&cols,int start,int parentColor)
{
    cols[start]=1-parentColor;
    for(auto &it:adj[start])
    {
        if(cols[it]==-1)
        {
            if(!bipartiteDFS(adj,cols,it,cols[start]))return false;//cycle found
        }
        else{
            if(cols[it]!=parentColor)
            return false;//cycle found
        }
    }
    return true;
}
bool bipartiteBFS(vector<vector<int>>&adj,vector<int>&cols,int start)
{
    queue<int>q;
    q.push(start);
    cols[start]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto &it:adj[node])
        {
            if(cols[it]==-1)
            {
                cols[it]=1-cols[node];
                q.push(it);
            }
            else if(cols[it]==cols[node])
            return false;
        }
    }
    return true;
}


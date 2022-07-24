#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC-> O(N+E)
//SC->O(2*N)
//Aux->O(N)
void topoDFS(vector<vector<int>>&adj,vector<int>&vis,int start,stack<int>&st)
{
    vis[start]=1;
    for(auto &it:adj[start])
    if(!vis[it])
    topoDFS(adj,vis,it,st);
    st.push(start);
}
//TC->O(N+E)
//SC->O(2*N)
void topoBFS(vector<vector<int>>&adj,vector<int>&vis,int start,vector<int>&topo)
{
    queue<int>q;
    vector<int>indegree(adj.size(),0);
    for(int i=0;i<adj.size();i++){indegree[i]=adj[i].size();
    if(indegree[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(auto &it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }



}
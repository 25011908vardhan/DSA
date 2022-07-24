#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void topoSort(vector<vector<pair<int,int>>>&adj,vector<int>&vis,int start,stack<int>&st)
{
    //Will Give me stack with topo sort
}
void spDAG(vector<vector<pair<int,int>>>adj,int src,int n)
{
    vector<int>vis(n,0);//for topo
    stack<int>st;
    for(int i=0;i<n;i++)
    if(!vis[i])
    topoSort(adj,vis,i,st);
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]==INT_MAX)continue;
        //We haven't reached here, therefore can't find shortest path from such node as if any other node reaches here with a shorter distance then all the changes that this node will make further will have to be changed, also it can't really make any changes as it's dist[node] itself is INT_MAX...
        for(auto &it:adj[node])
        {
            if(dist[it.first]>dist[node]+it.second)
            {
                dist[it.first]=dist[node]+it.second;
            }
        }

    }
    cout<<"Shortest Path in DAG with source "<<src<<"is : "<<endl;
    for(auto &it:dist)
    cout<<it<<" ";

}
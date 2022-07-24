#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//Undirected Graphs only...
//For all unit weights, we can just use queue as in spUndirectedGraphUnitWeights.cpp
//Here we make Min pq...such that node with shortest dist always at top of queue
//BFS Kind of algo
void dijkstra(vector<vector<pair<int,int>>>&adj,int src,int n)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        for(auto &it:adj[node])
        {
            if(dist[it.first]>dist[node]+it.second)
            {
                dist[it.first]=dist[node]+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    cout<<"Shortest Distance from source"<<src<<" is :"<<endl;
    for(auto &it:dist)cout<<it<<" ";
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void BFS(vector<int>adj[],int n,int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto &it:adj[node])
        {
            if(dist[it]>dist[node]+1)
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    cout<<"Shortest Distance in Undirected Graph with Unit Weights is from source"<<src<<": "<<endl;
    for(auto &it:dist)cout<<it<<" ";

}
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
    int u,v,wt;
    node(int start,int end,int weight)
    {
        u=start;
        v=end;
        wt=weight;
    }
};
bool comp(node a,node b)
{
    a.wt<b.wt;
}
int findP(int u,vector<int>&parent)
{
    if(u==parent[u])return u;
    return parent[u]=findP(parent[u],parent);
}
void unionn(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findP(u,parent);
    v=findP(v,parent);
    if(rank[u]>rank[v])
    parent[v]=u;
    else if(rank[u]<rank[v])
    parent[u]=v;
    else{
        parent[u]=v;
        rank[v]++;
    }
}
void kruskal(vector<vector<pair<int,int>>>&adj,int src,int n)
{
    vector<node>edges;
    vector<int>parent(n),rank(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        edges.push_back(node(i,adj[i][j].first,adj[i][j].second));
    }
    sort(edges.begin(),edges.end(),comp);
    for(int i=0;i<n;i++)parent[i]=i;
    int cost=0;//minCost Spanning Tree
    vector<pair<int,int>>mst;
    for(auto &it:edges)
    {
        if(findP(it.u,parent)!=findP(it.v,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    cout<<"MST Edges are: "<<endl;
    for(auto &it:mst)
    {
        cout<<it.first<<"--"<<it.second<<endl;
    }
}
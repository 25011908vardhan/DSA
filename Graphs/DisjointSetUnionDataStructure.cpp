#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int findP(int u,vector<int>&parent)
{
    if(u==parent[u])return u;
    return parent[u]=findP(parent[u],parent);//path compression
}
void unionn(int u,int v,vector<int>&parent,vector<int>&rank)//Union by rank
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
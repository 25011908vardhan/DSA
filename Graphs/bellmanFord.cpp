#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC->O(N-1)xO(E);
//SC->O(n)
struct node{
    int u,v,wt;
    node(int U,int V,int W)
    {
        u=U;
        v=V;
        wt=W;
    }
};
void bellmanFord(int n,int src)
{
//convert all the edges in form node(u,v,w);
    vector<node>edges(n);
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=1;i<=n-1;i++)
    //Exactly N-1 times Relaxation
    for(auto &it:edges)
    if(dist[it.u]+it.wt<dist[it.v])
    dist[it.v]=dist[it.u]+it.wt;//Edge Relaxed
    int flag=0;
    //Try relaxing one more time, if any edge further gets relaxed that means a negative cycle is present
    for(auto &it:edges)
    if(dist[it.u]+it.wt<dist[it.v])
    {
        cout<<"Negative Cycle Found"<<endl;
        flag=1;
        break;
    }
    if(!flag)
    {
        cout<<"Shortest Distance From Source"<<src<<" to nodes is : "<<endl;
        for(int i=0;i<n;i++)
        cout<<i<<"->"<<dist[i]<<endl;
    }
}

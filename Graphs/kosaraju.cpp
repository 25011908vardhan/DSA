#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//1st step-> sort all nodes on basis of finishing time which is Topo Sort
void topoDFS(vector<vector<int>>&adj,vector<int>&vis,int start,stack<int>&st)
{
    //returns topo sort in stack
    //Code in topo.cpp
}
//2nd Step-> Transpose the Graph
vector<vector<int>> transposeGraph(vector<vector<int>>&adj,vector<vector<int>>&transpose)
{
    int n=adj.size();
    
    for(int i=0;i<n;i++)
    for(int j=0;j<adj[i].size();j++)
    transpose[adj[i][j]].push_back(i);
    return transpose;
}
//3rd Step-> Do dfs according to finishing time i.e. topo sort.
void revDfs(int start,vector<int>&vis,vector<vector<int>>&adj)
{
    vis[start]=1;
    cout<<start<<" ";
    for(auto &it:adj[start])
    if(!vis[it])
    revDfs(it,vis,adj);
}
void kosaraju(vector<vector<int>>&adj,int n)
{
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++)
    topoDFS(adj,vis,i,st);
    vector<vector<int>>transpose(n);
    transposeGraph(adj,transpose);
    for(int i=0;i<n;i++)vis[i]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            cout<<"Strongly Conncected Components-> ";
            revDfs(node,vis,transpose);
            cout<<endl;
        }

    }
}
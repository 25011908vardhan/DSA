#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
// TC->O(N+E)
// SC->O(2*N)
//Aux->O(N)
bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&currDfs,int start)
{
    vis[start]=1;
    currDfs[start]=1;
    for(auto &it:adj[start])
    {if(!vis[it])
     {if(dfs(adj,vis,currDfs,it))
     return true;//cycle found
    }
    else{
        if(currDfs[it])return true;//found in current dfs
    }
    }
    currDfs[start]=0;
    return false;
} 
//BFS using kahn's
// TC->O(N+E)
// SC->O(2*N)
void bfs(){
    //find topo sort vector
    //Topo Sort is only possible for DAG
    //If it consists a cycle then topo sort's length !=number of nodes
    //return topo.size()==adj.size();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//TC->Theta (N^3)
void floydWarshall(vector<vector<pair<int,int>>>&adj,int n)
{
vector<vector<int>>spMat(n,vector<int>(n,INT_MAX));//ShortestPathMatrix
  for(int i=0;i<n;i++)
  for(auto &it:adj[i])
  spMat[i][it.first]=it.second;

  for(int k=0;k<n;k++)
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  spMat[i][j]=min(spMat[i][j],spMat[i][k]+spMat[k][j]);
}
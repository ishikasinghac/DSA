#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<in,set<int> > &adj,vector<int> &component)
{
    component.push_back(node);
    visited[node]=true;
    //recurssive call
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int> > DFS(int V,int e,vector<vector<int> >&edges)
{
// prepare adjency list
unordered_map<in,set<int> >adj;
for(int i=0;i<edges;i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<vector<int> >ans;
unordered_map<int,bool>visited;
for(int i=0;i<V;i++)
{
if(!visited[i])
{ 
    vector<int>component;
    dfs(i,visited,adj,component);
    ans.push_back(component);
}
}
}
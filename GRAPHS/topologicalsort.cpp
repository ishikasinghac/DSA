#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
void topsort(int node,unordered_map<int,bool>visited,stack<int>s,unordered_map<in,set<int> >adj)
{
    visited[node]=1;
    for(auto neighbours:adj[node])
    {
        if(!visited[neighbours])
        {
            topsort(neighbours,visited,s,adj);
        }
    }
    // imp
    s.push(node);
}

vector <int>topologicalsort(vector <vector<int> >&edges,int V,int E)
{
    unordered_map<in,set<int> >adj;
for(int i=0;i<edges;i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
}
// call dfs for topological sort
vector <vector<int> >ans;
unordered_map<int,bool>visited;
stack<int>s;
for(int i=0;i<V;i++)
{
if(!visited[i])
{ 
  topsort(i,visited,s,adj);
}
}
while(!s.empty())
{
    ans.push_back(s.top());
    s.pop();
}
return ans;
}
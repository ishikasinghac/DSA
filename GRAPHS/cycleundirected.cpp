#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>
using namespace std;

bool iscyclebfs(int src,unordered_map<bool,int> &visited,unordered_map<int,set<int> >&adj)
{
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
      
      for(auto neighbours: adj[front])
      {
          if(visited[neighbours]==true && neighbours!=parent[front])
          {
              return true;

          }
          else if(!visited[neighbours])
          {
              q.push(neighbours);
              visited[neighbours]=1;
              parent[neighbours]=1;

          }
      }
    }
    return false;
}
string cycledetect(vector<vector<int> >edges,int n,int m)
{
    unordered_map<int,set<int> >adj;
    for(int i=0;i<m;i++)
    {
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    // to handle disconnected components
    unordered_map<bool,int>visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=iscyclebfs(i,visited,adj);
            if(ans==1)
            {
                return "yes";
            }
        }
    }
    return "no";
}
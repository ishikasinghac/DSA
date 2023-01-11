#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void  makeadjlist(unordered_map<int,set<int> >&adjlist,vector<pair<int,int> >edges)
{
for(int i=0;i<edges.size();i++)
{
    int u=edges[i].first;
    int v=edges[i].second;
    adjlist[v].insert(u);
    adjlist[u].insert(v);
}
}
void bfs(unordered_map<int,set<int> >&adjlist,unordered_map<int,bool> &visited,vector<int>&ans,int node)
{
    queue<int>q;
    q.push(node);
    visited[node] =1;
    while(!q.empty())
    {
        int frontnode= q.front();
        q.pop();
        // store front node
        ans.push_back(frontnode);
        // traverse all neighbours
        for(auto i : adjlist[frontnode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }

    }
}

vector<int> BFS(int vertex,vector<pair<int,int> >edges)
{
    unordered_map<int,list<int> >adjlist;
    vector<int>ans;
    unordered_map<int,bool>visited;

    makeadjlist(adjlist,edges);
    // traverse all components
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}
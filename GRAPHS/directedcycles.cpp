#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>

using namespace std;

bool checkcycle(int node,unordered_map<int,bool> &visited,unordered_map<int,bool>&dfsvisited, unordered_map(int,list<int> &adj))
{
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto neighbours:adj[node])
    {
        if(!visited[neighbours])
        {
            bool cycledetect=checkcycle(neighbours,visited,dfsvisited,adj);
            if(cycledetect)
            return true;

        }
        else if(dfsvisited[neighbours])
        {
            return true;

        }
    }

}
int directedcycle(int n,vector<pair<int,int> >&edges)
{
    // create adj list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<edges.size();i++)
    {
     int u=edges[i].first;
     int v=edges[i].second;
     
     adj[u].push_back(v);
    }
    // call dfs for all components
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsvisited;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool cyclefound=checkcycle(i,visited,dfsvisited,adj);
            if(cyclefound)
            return true;
        }
    }
} 
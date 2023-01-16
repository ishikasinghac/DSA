#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>

vector<int> shortestpath(vector<pair<int,int>>edges, int n,int m,int s,int t)
{
unordered_map<int,list<int> >adjlist;
for(int i=0;i<edges;i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
    vector<int>ans;
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;

    queue<int>q;
    q.push(s);
    visited[s]=true;

    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto i:adj[front]);
        {
            if(!visited[i])
            {
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
        
    }
//   prepare shortest path
vector<int>ans;
int currentNode= t;
ans.push_back(t);
while(currentNode!=s)
{
currentNode=parent[currentNode];
ans.push_back(currentNode);
}
return ans;
}
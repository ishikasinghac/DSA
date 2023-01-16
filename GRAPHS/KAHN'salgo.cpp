#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>

using namespace std;
vector <int>topologicalsort(vector <vector<int> >&edges,int V,int E)
{
    unordered_map<int,list<pair<int,int> >adj;
for(int i=0;i<edges;i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
}
// find all indegrees
vector<int> indegree(v);
for(auto i:adj)
{
for(auto j:i.second)
{
    indegree[j]++;
}
}
// push 0 indegree
queue<int>q;
for(int i=0;i<v;i++)
{
if(indegree[i]==0)
q.push(i);
}

// do bfs
vector<int>ans;
while(!q.empty())
    {
        int front= q.front();
        q.pop();
        // store front node
        ans.push_back(front);
        // traverse all neighbours
        for(auto i : adj[front])
        {
           indegree[neighbours]--;
           if(indegree[neighbours]==0)
           q.push[neighbours];
        }

    }
    return ans;

}
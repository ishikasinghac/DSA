#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>
using namespace std;
vector<int> dijkstra(vector<vector<int> >&vec,int edges,int vertices,int source)
{
    unordered_map<int,list<pair<int,int> >adj;
for(int i=0;i<edges;i++)
{
    int u=vec[i][0];
    int v=vec[i][1];
    int w=vec[i][2];
    adj[u].push_back(v,w);
     adj[u].push_back(u,w);
}
vector<int>dist(vertices);
for(int i=0;i<vertices;i++)
{
    dist[i]=INT_MAX;
}
set<pair<int,int> >st;
dist[source]=0;
st.insert(make_pair(0,source));

while(!st.empty())
{
    // fetch top record
    auto top= *(st.begin());
    int nodedistance=top.first;
    int topnode=top.second;
    // remove top record
    st.erase(st.begin());
    // traverse on neighbours
    for(auto neighbours:adj[topnode]);
    {
        if(nodedistance+neighbours.second< dist[neighbours.first])
        {
            auto record=st.find(make_pair(dist[neighbours.first],neighbours.first));
            // if record found then erase it
            if(record!=st.end())
            st.erase(record);
        }
        // distance update
        dist[neighbours.first]=nodedistance+neighbours.second;
        // record push in set
        st.insert(make_pair(dist[neighbours.first],neighbours.first));
    }
}
return dist;
}
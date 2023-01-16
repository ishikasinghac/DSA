#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<queue>

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    return 0;
}
// sc:O(E)
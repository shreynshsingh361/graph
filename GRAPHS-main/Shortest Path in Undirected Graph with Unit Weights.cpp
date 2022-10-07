#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void bfs(vector<int>adj[],int n,int src)
{  
    vector<int>dist(n,INT_MAX);
    queue<int>q;
    q.push(src);
    dist[src]=0;
 
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();  
      
    for(int neigh:adj[fr])
    {
        if(1+dist[src]<dist[neigh])
           dist[neigh]=dist[src]+1;
           q.push(neigh);
        }
    }
    for(auto x:dist)
    cout<<x<<" ";
}
int main() {
    int n,m,u,v,src;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>src;
    bfs(adj,n,src);
    return 0;
}

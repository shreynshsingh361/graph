#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkbfs(int i,vector<int>adj[],vector<int>&vis,vector<int>dfsvis)
{
    cout<<i<<" ";
    vis[i]=1;
    dfsvis[i]=1;
             for(int neigh:adj[i])
        {
            if(!vis[neigh])
            {
             if(checkbfs(neigh,adj,vis,dfsvis)) return true; 
            }
            else if(dfsvis[i]==1)return true;
          
        } dfsvis[i]=0;
    return false;
}
int main() {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    vector<int>dfsvis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            bool ans=checkbfs(i,adj,vis,dfsvis);
          
            if(ans==true)
            cout<<"CYCLE FOUND"<<" ";
            else
            cout<<"NOT FOUND";
        }
    }
    return 0;
}
/*
Input
3 3
1 2 1 3 2 3
Output
1 2 3 CYCLE FOUND 
*/

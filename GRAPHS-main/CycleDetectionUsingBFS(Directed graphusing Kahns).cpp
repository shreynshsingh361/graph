#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool bfs(vector<int>adj[],int n)
{  
    vector<int>indeg(n,0);
      vector<int>top;
    queue<int>q;
   for(int i=0;i<n;i++)
   {
       for(auto it:adj[i])
       {
           indeg[it]++;
       }
   }
   int c=0;
    for(int i=0;i<n;i++)
   {
       if(indeg[i]==0)
       q.push(i);
   }

    while(!q.empty())
    {
        int fr=q.front();
        q.pop();  
        c++;
        top.push_back(fr);
        //cout<<fr<<" ";
    for(int neigh:adj[fr])
    {
        indeg[neigh]--;
        if(indeg[neigh]==0)
            q.push(neigh);
        }
    }
    if(c==n)return true;
    return false;
}
int main() {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ans=bfs(adj,n);
   if(ans==true)cout<<"CYCLE PRESENT";
   else
   cout<<"NO CYCLE";
    return 0;
}
/*
Input
6 6
2 3 3 1 4 0 4 1 5 1 5 2
Output
CYCLE PRESENT
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int V,m,u,v;
    cin>>V>>m;
    vector<int>adj[V+1];
    for(int i=0;i<m;i++)
    {
        adj[i].push_back(v);
    }
        queue<int>q;
	    int job[V];
	    vector<int>indeg(V,0);
	    for(int i=0;i<V;i++)
	    {
	          for(auto neigh:adj[i])
	          {
	              indeg[neigh]++;
	          }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indeg[i]==0)
	        {
	            q.push(i);
                job[i]=1;
	        }
	    }
	 while(!q.empty())
	 {
	     int fr=q.front();
	     q.pop();
	     
	     for(auto neigh:adj[fr])
	     {
	         indeg[neigh]--;
	         if(indeg[neigh]==0)
	         q.push(neigh);
             job[neigh]=job[fr]+1;
	     }
     }
	     for (int i = 0; i <V; i++)
        cout << job[i] << " ";
    cout << "\n"; 
}

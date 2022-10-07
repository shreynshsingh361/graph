#include <bits/stdc++.h> 
#define INF INT_MAX 
#include<queue>
using namespace std;

int main() 
{ 
	int n, m,src;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
    vector<int>parent{n,0};
    vector<int>key{n,INT_MAX};
    vector<bool>set(n,false);
    key[0]=0;
    parent[0]=-1;
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   pq.push({0,0});
    for(int i=0;i<n-1;i++)
    {
      int u=pq.top().second;
      pq.pop();
        set[u]=true;
        for(auto neigh:adj[u])
        {
            int val=neigh.first;
            int weight=neigh.second;
            if(weight<key[val])
            {
                parent[val]=u;
                key[val]=weight;
                pq.push({key[val],val});
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
	return 0; 
} 

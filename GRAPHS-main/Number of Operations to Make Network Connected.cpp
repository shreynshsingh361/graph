class Solution {
public:
     void dfs(vector<int> adj[],int start,vector<bool>& vis)
       {   vis[start]=true;
           for(auto node: adj[start])
             {  if(!vis[node])                                         
                   dfs(adj,node,vis);             
            }
        
      }
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<int> adj[n];
         for(int i=0;i<connections.size();i++)
                {  adj[connections[i][0]].push_back(connections[i][1]);   
                   adj[connections[i][1]].push_back(connections[i][0]);   
                }
        
        vector<bool> vis(n,false);
        int connected_comp=0;
        for(int i=0;i<n;i++)
          {
              if(!vis[i])
                {   connected_comp++;                
                   dfs(adj,i,vis);
                }
         }
        if(connections.size()>=n-1)      
            return connected_comp-1;  
         if(connections.size()<n-1)
             return -1;                         
        return 0;
        
    }
    
};

class Solution{
    public:
    void dfs(vector<vector<int>>&g,vector<int>&vis,int i,string &ans)
    {
        vis[i]=1;
        for(auto neigh:g[i])
        {
            if(!vis[neigh])
            {
                dfs(g,vis,neigh,ans);
            }
        }
        char ch=i+'a';
          ans =ch+ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
         string ans="";
        vector<vector<int>>g(K);
        for(int i=0;i<N-1;i++)
        {
        string w1=dict[i];
        string w2=dict[i+1];
        for(int j=0;j<min(w1.length(),w2.length());j++)
        {
            if(w1[j]!=w2[j])
            {
                g[w1[j]-'a'].push_back(w2[j]-'a');
                  break;
            }
        }
        }
        vector<int>vis(K,0);
       
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
            {
                dfs(g,vis,i,ans);
            }
        }
        return ans;
    }
};

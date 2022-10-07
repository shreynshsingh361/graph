
class Solution{
    public:
    void solve(int i,int j,vector<vector<int>>&m,int n,vector<string>&ans,string move,int di[],int dj[],vector<vector<int>>&vis)
    {
        if(i==n-1 && j==n-1)
        {
        ans.push_back(move);
        return;
        }
        string dir="DLRU";
        for(int in=0;in<4;in++)
        {
            int diri=i+di[in];
            int dirj=j+dj[in];
            if(diri>=0 && dirj>=0 && diri<n && dirj<n && !vis[diri][dirj] && m[diri][dirj]==1)
            {
                vis[i][j]=1;
                solve(diri,dirj,m,n,ans,move+dir[in],di,dj,vis);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(m[0][0]==1)
        {
            solve(0,0,m,n,ans,"",di,dj,vis);
        }
        return ans;
    }
};

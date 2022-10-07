class Solution {
public:
    void dfs( vector<vector<int>>&vis,vector<vector<int>>& image, int i, int j, int newColor,int old,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)
        {
            return;
        }
        if(vis[i][j]||image[i][j]!=old)return;
        vis[i][j]=1;
        image[i][j]=newColor;
        
        dfs(vis,image,i+1,j,newColor,old,m,n);
         dfs(vis,image,i-1,j,newColor,old,m,n);
        dfs(vis,image,i,j+1,newColor,old,m,n);
        dfs(vis,image,i,j-1,newColor,old,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x=image.size();
        int y=image[0].size();
        vector<vector<int>>vis(x,vector<int>(y,0));
        int old=image[sr][sc];
        dfs(vis,image,sr,sc,newColor,old,x,y);
       return image;
    }
};

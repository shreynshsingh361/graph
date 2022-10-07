lass Solution 

{
    struct data
    {
        int x,y;
        int dis;
        data()
        {
        }
        data(int xcor,int ycor,int dist)
        {
            x=xcor;
            y=ycor;
            dis=dist;
        }
    };
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
bool valid(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N)
	{
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        queue<data>q;
        q.push(data(knightPos[0], knightPos[1], 0));
	    // Code here
	    int x, y;
	    data pos;
        bool visit[N + 1][N + 1];
          for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
            visit[knightPos[0]][knightPos[1]] = true;
            while (!q.empty()) {
             pos= q.front();
           q.pop();
           if (pos.x == targetPos[0] && pos.y == targetPos[1])
            return pos.dis;
              for (int i = 0; i < 8; i++) {
            x = pos.x + dx[i];
            y = pos.y + dy[i];
            if (valid(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(data(x, y, pos.dis + 1));
            }
        }
    }
	}
};

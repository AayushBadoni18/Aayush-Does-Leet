class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //dimensions of the grid
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int count_1 = 0;
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        count_1++;
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
                else if(grid[i][j]==1)count_1++;
            }
        }
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        int hehe = q.size();
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            vis[x][y] = 1;
            q.pop();
            for(int i = 0; i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny] = 1;
                    hehe++;
                    q.push({nx,ny});
                }
            }
        }
        return count_1-hehe;
    }
};
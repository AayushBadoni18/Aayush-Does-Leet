class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i =0 ; i<n ;i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else continue;
            }
        }
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {-1,1,0,0};
        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            ans[row][col] = dist;
            q.pop();
            for(int i = 0; i<4;i++){
                int nx = row+dy[i];
                int ny = col+dx[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 ){
                    vis[nx][ny] = 1; 
                    q.push({{nx, ny},dist+1});
                }
            }
        }
        return ans;
    }
};
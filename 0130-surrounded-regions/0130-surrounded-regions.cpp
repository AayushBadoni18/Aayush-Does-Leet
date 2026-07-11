class Solution {

private:
    //DFS function
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = board.size(), m = board[0].size();
        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k], ncol = col + delcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }
public:
    //Interview prep
    void solve(vector<vector<char>>& board) {
        //Any boundary O connected with other Os will not be replaced
        //Declaring vector dimensions
        int n = board.size();
        int m = board[0].size();
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') dfs(0, j, vis, board, delrow, delcol);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') dfs(n - 1, j, vis, board, delrow, delcol);
        }

        // traverse first and last column
        for (int i = 0; i < n; i++) {
            // start DFS from unvisited boundary 'O' (left col)
            if (!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board, delrow, delcol);
            // start DFS from unvisited boundary 'O' (right col)
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') dfs(i, m - 1, vis,board, delrow, delcol);
        }

        // flip all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // convert enclosed 'O' to 'X'
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
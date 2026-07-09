class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =  grid[0].size();
        vector<vector<int>> next(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) next[j1][j2] = grid[n-1][j1];
                else next[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    int currChoco = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;
                            if (newJ1 >= 0 && newJ1 < m &&
                                newJ2 >= 0 && newJ2 < m) {
                                maxi = max(maxi, currChoco + 
                                           next[newJ1][newJ2]);
                            } else {
                                maxi = max(maxi, (int)-1e9);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            next = curr;
        }
        return next[0][m-1];
    }
};
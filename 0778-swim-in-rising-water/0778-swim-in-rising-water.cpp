class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        typedef pair<int,pair<int, int>> p;
        int n = grid.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> time(n, vector<int> (n, 1e9));
        pq.push({grid[0][0], {0, 0}});

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        while(!pq.empty()) {
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n - 1 && col == n - 1) return t;

            for(int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int swimTime = t >= grid[nr][nc] ? t : grid[nr][nc];
                    if(time[nr][nc] > swimTime) {
                        pq.push({swimTime, {nr, nc}});
                        time[nr][nc] = swimTime;
                    }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;   // visiting

        for (int next : adj[node]) {
            if (vis[next] == 0) {
                if (dfs(next, vis, adj))
                    return true;
            }
            else if (vis[next] == 1) {
                return true;   // back edge -> cycle
            }
        }

        vis[node] = 2;   // processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, vis, adj))
                    return false;
            }
        }

        return true;
    }
};
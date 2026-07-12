class Solution {
public:
    bool dfs(vector<int>& color, vector<int>& vis, bool b, vector<vector<int>>& graph, int u) {
        if(color[u]==!b) return false;
        color[u] = b;
        if(vis[u]) return true;
        vis[u] = 1;
        for(int v : graph[u]) {
            if(!dfs(color, vis, !b, graph, v)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        vector<int> vis(graph.size(), 0);
        for(int i = 0; i<graph.size(); i++) {
            if(!vis[i] && !dfs(color, vis, 0, graph, i)) return false;
        }
        return true;
    }
};
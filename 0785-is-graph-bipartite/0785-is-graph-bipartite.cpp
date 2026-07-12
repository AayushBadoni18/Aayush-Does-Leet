class Solution {
public:
    bool check(int node, int parent, vector<int>& vis,
               vector<vector<int>>& graph, int color) {

        queue<pair<pair<int,int>,int>> q;

        vis[node] = color;
        q.push({{node, parent}, color});

        while(!q.empty()) {

            int node = q.front().first.first;
            int parent = q.front().first.second;
            int color = q.front().second;
            q.pop();

            for(auto it : graph[node]) {

                if(vis[it] == -1) {
                    vis[it] = !color;
                    q.push({{it, node}, !color});
                }
                else if(vis[it] == color) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> vis(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++) {
            if(vis[i] == -1) {
                if(!check(i, -1, vis, graph, 0))
                    return false;
            }
        }

        return true;
    }
};
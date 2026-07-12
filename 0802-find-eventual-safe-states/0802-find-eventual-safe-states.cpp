class Solution {
private:
    bool dfs(int node, vector<int>&vis, vector<int>&pathvis,vector<vector<int>>& graph,vector<int>&check){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,vis, pathvis, graph, check)==true)return true;
            }
            else if(pathvis[it])return true;
        }
        check.push_back(node);
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        vector<int>check;
        for(int i = 0; i< v; i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph, check);
            }
        }
        sort(check.begin(),check.end());
        return check;
    }
};
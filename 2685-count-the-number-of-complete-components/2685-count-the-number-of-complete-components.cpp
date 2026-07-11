class Solution {
public:
    using int2=pair<int, int>;
    vector<int2> adj[50];
    bitset<50> viz=0;
    bitset<1250>  Eviz=0;
    int2 dfs(int i){
        viz[i]=1;
        int v=1, e=0;
        for(auto& [j, eIdx]: adj[i]){
            e+=(1-Eviz[eIdx]);
            Eviz[eIdx]=1;
            if (viz[j]) continue;
            auto [v0, e0]=dfs(j);
            e+=e0;
            v+=v0;
        }
        return {v, e};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        const int m=edges.size();
        if(m==n*(n-1)/2) return 1;
        for(int i=0; i<m; i++){
            const int v=edges[i][0], w=edges[i][1];
            adj[v].emplace_back(w, i);
            adj[w].emplace_back(v, i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if (viz[i]) continue;
            auto [v, e]=dfs(i);
            ans+=e==v*(v-1)/2;
        }
        return ans;
    }
};
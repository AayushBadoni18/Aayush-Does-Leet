class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        int extraEdges = 0;

        for(auto &edge : edges){
            int p1 = findParent(edge[0], parent);
            int p2 = findParent(edge[1], parent);

            if(p1 == p2){
                extraEdges++;
            }
            else{
                n--;
            }
            parent[p2] = p1;
        }

        return extraEdges >= n - 1 ? n - 1 : -1;
    }

    int findParent(int node, vector<int>& parent){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }
};
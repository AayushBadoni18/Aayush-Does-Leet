class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        vector<int>topo;
        for(int i =0; i< numCourses; i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return (topo.size()==numCourses)?topo:vector<int>{};
    }
};
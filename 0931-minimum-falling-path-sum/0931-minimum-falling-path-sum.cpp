class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int i = 0; i<n;i++){
            prev[i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0; j<n;j++){
                int down = matrix[i][j]+prev[j];
                if(j>0){
                    int left = matrix[i][j]+prev[j-1];
                    down = min(down,left);
                }
                if(j<n-1){
                    int right = matrix[i][j]+prev[j+1];
                    down = min(down,right);
                }
                curr[j] = down;
            }
            prev = curr; 
        }
        int maxi = prev[0];
        for(auto it: prev){
            maxi = min(maxi, it);
        }
        return maxi;
    }
};
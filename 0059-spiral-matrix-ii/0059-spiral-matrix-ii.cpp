
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int cnt = 1;

        while (top <= bottom && left <= right) {
            // Left to Right
            for (int j = left; j <= right; j++) {
                ans[top][j] = cnt++;
            }
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = cnt++;
            }
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans[bottom][j] = cnt++;
                }
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = cnt++;
                }
                left++;
            }
        }
        return ans;
    }
};
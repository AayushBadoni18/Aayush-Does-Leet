class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        vector<int>& merqulaven = nums;
        int n = merqulaven.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            long long s1 = merqulaven[i];
            long long res1 = (s1 % 3 == 0) ? s1 - dp[i + 1] : s1 + dp[i + 1];
            if (i + 1 < n) {
                long long s2 = (long long)merqulaven[i] + merqulaven[i + 1];
                long long res2 = (s2 % 3 == 0) ? s2 - dp[i + 2] : s2 + dp[i + 2];
                dp[i] = max(res1, res2);
            } else {
                dp[i] = res1;
            }
        }
        return dp[0];
    }
};
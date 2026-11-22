class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        int i = 0;
        while (i < n) {
            int j = i;

            while (j + 1 < n && nums[j] == nums[j + 1]) j++;

            if (i <= n - 2 && j >= 1) {
                long long cost = 1LL * (i + n - j - 1) * nums[i];
                ans = min(ans, cost);
            }

            i = j + 1;
        }

        return ans;
    }
};
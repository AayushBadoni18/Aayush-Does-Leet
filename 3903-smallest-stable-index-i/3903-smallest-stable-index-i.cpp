class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> copy = nums;

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            copy[i] = maxi;
        }

        int mini = INT_MAX;
        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);

            if (copy[i] - mini <= k)
                ans = i;
        }

        return ans;
    }
};
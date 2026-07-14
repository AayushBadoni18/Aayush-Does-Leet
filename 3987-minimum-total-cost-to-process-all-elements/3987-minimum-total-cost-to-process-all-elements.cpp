class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        vector<long long> a(nums.begin(), nums.end());
        long long MOD = 1e9 + 7;
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        long long K = k;
        long long need = (((sum + K - 1) / K) - 1) % MOD;
        return ((need * (need + 1)) / 2) % MOD;
    }
};
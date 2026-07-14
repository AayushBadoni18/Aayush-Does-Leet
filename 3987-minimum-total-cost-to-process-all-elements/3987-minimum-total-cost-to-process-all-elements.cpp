class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long mod = 1e9 + 7;
        const long long inv2 = 500000004;

        long long mult = 0;
        long long resources = k;

        for (int it : nums) {
            if (it <= resources) {
                resources -= it;
            } else {
                long long need = it - resources;
                long long n = (need + k - 1) / k;   // ceil(need/k)

                mult += n;
                resources += n * 1LL * k;
                resources -= it;
            }
        }

        long long ans = (mult % mod) * ((mult + 1) % mod) % mod;
        ans = ans * inv2 % mod;

        return (int)ans;
    }
};
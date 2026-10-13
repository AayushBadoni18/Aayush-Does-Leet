class Solution {
public:
    const static unsigned mod=1e9+7;
    static int maxSum(vector<int>& nums, int k) {
        static array<int, 31> Bit{};
        Bit.fill(0);
        for(unsigned x: nums){
            for(unsigned mask=x; mask; mask&=(mask-1)){
                Bit[countr_zero(mask)]++;
            }
        }
        unsigned long long ans=0;
        for(int i=0; i<k; i++){
            unsigned long long x=0;
            for(int b=0; b<31; b++){
                x+=(Bit[b]-->0)<<b;
            }
            ans=(ans+x*x)%mod;
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int gcd_num(int a, int b){
        while(a>0 && b>0){
            if(a>=b)a%=b;
            else b%=a;
        }
        return max(a,b);
    }
    int findGCD(vector<int>& nums) {
        int mini = nums[0],maxi = nums[0];
        for(auto it: nums){
            mini = min(mini, it);
            maxi = max(maxi, it);
        }
        return gcd_num(mini, maxi);
    }
};
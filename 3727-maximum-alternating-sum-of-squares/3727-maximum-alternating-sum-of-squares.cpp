class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &it : nums){
            if(it<0)it*=-(1);
        }
        sort(nums.begin(), nums.end());
        // for(auto it: nums)cout<<it<<" ";
        int l = nums.size()/2;
        long long total = 0;
        for(int i = 0; i<l;i++)total-=(long long)(nums[i]*nums[i]);
        for(int i = l; i<nums.size();i++)total+=(long long)(nums[i]*nums[i]);
        return total;
    }
};
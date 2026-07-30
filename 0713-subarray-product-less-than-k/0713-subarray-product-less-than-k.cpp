class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mult = 1;
        int left = 0,right = 0;
        int count = 0;
        while(right<nums.size()){
            mult*=nums[right];
            while(mult>=k && left<=right)
            {
                mult/=nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};
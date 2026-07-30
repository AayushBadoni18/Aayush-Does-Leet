class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int left = 0;
        int sum = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum > k) {
                sum -= nums[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size();i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        
        return atMost(nums,k)-atMost(nums,k-1);
    }
};
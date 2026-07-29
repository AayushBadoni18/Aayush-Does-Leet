class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>> st;
        for(int i = 0; i < nums.size(); i++) {

            if(st.empty() || st.top().first > nums[i]) {
                st.push({nums[i], i});
            }
        }
        int ans = 0;
        for(int j = nums.size()-1; j >= 0; j--) {
            while(!st.empty() && st.top().first <= nums[j]) {
                ans = max(ans, j - st.top().second);
                st.pop();
            }
        }
        return ans;
    }
};
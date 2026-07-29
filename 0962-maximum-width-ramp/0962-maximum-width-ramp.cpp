class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        int max_width = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                max_width = max(max_width, j - st.top());
                st.pop();
            }
        }
        return max_width;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int>ans;
        int start_window = (int)log10(low) +1;
        int end_window = (int)log10(high)+1;
        for(int i = start_window; i<=end_window;i++){
            int start = 0;
            int end = start+i;
            while(end<=9){
                int num = stoi(str.substr(start,i));
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
                start++;
                end++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
        return {};
        vector<string>sol;
        string word="";
        int start=nums[0],i=1,end=nums[0];
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1)
                end=nums[i];
            else{
                if(start==end)
                    sol.push_back(to_string(start));
                else{
                    string word="";
                    word+=to_string(start);
                    word+="->";
                    word+=to_string(end);
                    sol.push_back(word);
                }
                start=nums[i];
                end=nums[i];
            }
            i++;
        }
        if(start==end)
            sol.push_back(to_string(start));
        else{
            string word="";
                    word+=to_string(start);
                    word+="->";
                    word+=to_string(end);
                    sol.push_back(word);
        }
        return sol;

    }
};
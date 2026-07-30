class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.size() > s.size())
            return {};

        map<char,int> mpp1, mpp2;

        for(char c : p)
            mpp2[c]++;

        vector<int> ans;

        int left = 0;

        for(int right = 0; right < s.size(); right++)
        {
            mpp1[s[right]]++;
            if(right - left + 1 == p.size())
            {
                if(mpp1 == mpp2)
                    ans.push_back(left);
                mpp1[s[left]]--;
                if(mpp1[s[left]] == 0)
                    mpp1.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
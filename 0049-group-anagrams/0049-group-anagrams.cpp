class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<string>demo;
        vector<int>vis(strs.size(), 0);
        for(int i = 0; i< strs.size();i++){
            string a = strs[i];
            sort(a.begin(),a.end());
            demo.push_back(a);
        }
        for(int i = 0; i< strs.size();i++){
            if(!vis[i]){
                vis[i]=1;
                string str = strs[i];
                vector<string>pre;
                pre.push_back(strs[i]);
                for(int j = i+1; j< strs.size(); j++){
                    if(demo[i]==demo[j]){
                        pre.push_back(strs[j]);
                        vis[j]=1;
                    }
                }
                ans.push_back(pre);
            }
        }
        return ans;
    }
};
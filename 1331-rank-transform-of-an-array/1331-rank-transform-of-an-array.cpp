class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank =1;
        vector<int>a =arr;
        sort(a.begin(),a.end());
        unordered_map<int,int>mpp;
        for(auto it: a){
            if(mpp.find(it)==mpp.end()){
                mpp[it] = rank;
                rank++;
            }
        }
        vector<int>res;
        for(auto it : arr){
            res.push_back(mpp[it]);
        }
        return res;
    }
};
class Solution {
public:
    string ret(string s, int k){
        string str = "";
        int sum = 0;
        int group = 0;
        int i = 0;
        while(i<s.size()){
            if(group==k){
                str+= to_string(sum);
                sum = 0;
                group = 0;
            }
            sum+=(s[i]-'0');
            i++;
            group++;
        }
        if(group!=0)str+= to_string(sum);
        return str;
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            s = ret(s,k);
        }
        return s;
    }
};
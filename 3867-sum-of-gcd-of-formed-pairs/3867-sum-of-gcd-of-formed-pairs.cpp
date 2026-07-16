class Solution {
private:
    long long gcd_num(long long  a , long long b){
        while(a>0 && b>0){
            if(a>=b)a%=b;
            else if(b>a)b%=a;
        }
        return max(a,b);
    }
public:

    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        vector<int>p;

        for(int i = 0; i< nums.size();i++){
            maxi = max(maxi, nums[i]);
            p.push_back(gcd_num(maxi, nums[i]));
        }
        sort(p.begin(), p.end());
        int left = 0, right = p.size()-1;
        long long sum = 0;
        while(left<right){
            sum+=(gcd_num(p[left], p[right]));
            left++;
            right--;
        }
        return sum;
    }
};
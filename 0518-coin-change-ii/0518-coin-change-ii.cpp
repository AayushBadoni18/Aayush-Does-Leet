class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int amt = amount;
        vector<unsigned long long>dp(amt+1,0);
        dp[0]=1;
        for(int coin: coins){
            for(int i=coin;i<=amt;i++){
                dp[i]+=dp[i-coin];
            }
        }
        return dp[amt];
        
    }
};
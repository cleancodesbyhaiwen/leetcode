class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        

        vector<int> dp(cost.size()+1, 0);
        dp[dp.size()-2] = cost[cost.size()-1];

        
        for(int i = dp.size() - 3;i >= 0;i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};
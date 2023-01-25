class Solution {
public:

    int climbStairs(int n) {
        
        int n1 = 1;
        int n2 = 1;
        
        for(int i = 0;i < n - 1;i++){
            int temp = n1;
            n1 = n1 + n2;
            n2 = temp;
        }
        
        return n1;
    }
};


class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int result = recur(n, dp);
        return result;

    }
    
    int recur(int n, vector<int>& dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] == -1){
            dp[n] = recur(n-1, dp)+recur(n-2,dp);
        }
        return dp[n];        
    }
};


class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        
        int dp1 = 1;
        int dp2 = 1;
        int tmp;
        for(int i = 2;i <= n;i++){
            tmp = dp1;
            dp1 = dp2;
            dp2 = tmp + dp2;
        }
        return dp2;
    }
};
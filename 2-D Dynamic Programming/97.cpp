// DP matrix
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.size();
        int n = s2.size();
        
        int z = s3.size();
        
        if(m+n != z){
            return false;
        }
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
        
        dp[m][n] = true;
        
        for(int i = m;i >= 0;i--){
            for(int j = n;j >= 0;j--){
                if(dp[i][j] == 0)
                {
                    if(i == m){
                        dp[i][j] = (s3[i+j]==s2[j] && dp[i][j+1]) ? true : false;
                    }
                    else if(j == n){
                        dp[i][j] = (s3[i+j]==s1[i] && dp[i+1][j]) ? true : false;
                    }
                    else{
                        dp[i][j] = (dp[i+1][j] && s1[i] == s3[i+j])  || (dp[i][j+1] && s2[j] == s3[i+j]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
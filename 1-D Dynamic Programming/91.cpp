class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size()+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        if(s[0] == '0'){
            cout<<"yes"<<endl;
            dp[0] = 0;
            dp[1] = 0;            
        }
        
        for(int i = 2;i <= s.size();i++){
            int last = stoi(s.substr(i-1,1));
            if(last >= 1 && last <= 9){
                dp[i] += dp[i-1];
            }
            int last_two = stoi(s.substr(i-2,2));
            if(last_two >= 10 && last_two <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()]; 
    }
};
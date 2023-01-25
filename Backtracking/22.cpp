class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        GP(n, result, 0, 0, "");
        return result;
        
    }
    
    void GP(int n, vector<string>& result, int left, int right, string s){
        if(left == n && right == n){
            result.push_back(s);
            return;
        }
        if(left < n){
            GP(n, result, left+1,right,s+'(');
        }
        if(left>right){
            GP(n, result,left,right+1,s+')');
        }
    }
};
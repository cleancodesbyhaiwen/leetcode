class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        dfs (s, 0, curr, result);
        return result;
    }
    
    void dfs(string s, int index, vector<string>& curr, vector<vector<string>>& result){
        
        if(index == s.size()){
            result.push_back(curr);
        }
        for(int i = index;i < s.size();i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i-index+1));
                dfs(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
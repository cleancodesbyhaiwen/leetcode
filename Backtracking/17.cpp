class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()){
            return {};
        }
        
        unordered_map<char, string> num_letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        string curr;
        vector<string> result;
        dfs(result, 0, digits, curr,num_letters);
        return result;
    }
    
    void dfs(vector<string>& result, int index, string digits, string& curr, unordered_map<char, string>& num_letters){

        if(index == digits.size()){
            result.push_back(curr);
            return;
        }
        
        for(int i = 0; i < num_letters[digits[index]].size();i++){
            curr.push_back(num_letters[digits[index]][i]);
            dfs(result, index+1, digits, curr, num_letters);
            curr.pop_back();
        }
    }
};
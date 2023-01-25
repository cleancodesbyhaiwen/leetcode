class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        vector<vector<int>> result;
        dfs(result, nums, 0, curr);
        return result;
        
        
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& nums, int index, vector<int>& curr){

        result.push_back(curr);
        for(int i = index;i < nums.size();i++){
            curr.push_back(nums[i]);
            dfs(result, nums, i + 1, curr);
            curr.pop_back();
        }
    }
};
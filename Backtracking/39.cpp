class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> curr;
        dfs(candidates, result,0, curr,target, 0);
        return result;
        
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& result, int curr_sum, vector<int>& curr,int target, int index){
        
        if(curr_sum == target){
            result.push_back(curr);
            return;
        }else if(curr_sum  > target){
            return;
        }
        
        for(int i = index;i < nums.size();i++){
            curr.push_back(nums[i]);
            dfs(nums, result,curr_sum+nums[i], curr,target, i);
            curr.pop_back();
        }
    }
};


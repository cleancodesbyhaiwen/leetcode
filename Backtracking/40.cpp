class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        dfs(result, candidates, curr, 0,target,0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& curr, int curr_sum, int target ,int index){
        
        if(curr_sum == target){
            result.push_back(curr);
            return;
        }
        if(curr_sum > target){
            return;
        }
        for(int i = index;i < candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            dfs(result, candidates, curr, curr_sum+candidates[i],target, i + 1);
            curr.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> result;
        dfs(result, curr,nums,0);
        return result;
    }
    
    
    void dfs(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums, int index){
        
        result.push_back(curr);

        for(int i = index;i < nums.size();i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            
            curr.push_back(nums[i]);
            dfs(result, curr, nums, i+1);
            curr.pop_back();
        }
    }
};
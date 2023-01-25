class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        dfs(result, nums, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& nums, int index){
        
        if(index >= nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i = index;i < nums.size();i++){
            swap(nums, index, i);
            dfs(result, nums, index+1);
            swap(nums, index, i);
        }
    }
    
    
    void swap(vector<int> &nums, int index1, int index2){
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
};
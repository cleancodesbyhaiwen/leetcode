// Brute Force
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        recur(nums, target, 0, 0, result);
        return result;
    }
    
    
    void recur(vector<int>& nums, int target, int index, int sum, int& result){
        if(index == nums.size()){
            if(sum == target){
                result++;
            }
            return;
        }
        recur(nums, target, index+1, sum-nums[index], result);
        recur(nums, target, index+1, sum+nums[index], result);
    }
    
};

// Caching
class Solution {
public:
    
    map<pair<int, int>, int> m;
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums, target, 0, 0);
    }
    
    
    int recur(vector<int>& nums, int target, int index, int sum){
        
        if(index == nums.size()){
            return (sum==target) ? 1 : 0;
        }
        if(m.find({index, sum}) != m.end()){
            return m[{index, sum}];
        }
        m[{index,sum}] = recur(nums, target, index+1, sum-nums[index]) +
            recur(nums, target, index+1, sum+nums[index]);
        return m[{index, sum}];
    }
};
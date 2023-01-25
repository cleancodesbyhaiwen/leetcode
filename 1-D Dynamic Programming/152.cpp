class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        
        for(int i = 1;i < nums.size();i++){
            int tmp = currMax;
            
            currMax = max(max(currMax*nums[i],currMin*nums[i]),nums[i]);
            currMin = min(min(currMin*nums[i],tmp*nums[i]),nums[i]);
            
            result = max(currMax,result);
        }
        return result;
        
    }
};
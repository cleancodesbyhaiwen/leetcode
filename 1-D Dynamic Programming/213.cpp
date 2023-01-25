class Solution {
public:
    
    int maxRob(vector<int> nums){
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        int n = nums.size();
        
        vector<int> dp(nums.size(),0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(dp[n-1],dp[n-2]);
    }
    
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        vector<int> nums1(nums.size()-1);
        vector<int> nums2(nums.size()-1);
        
        for(int i = 0;i < nums.size()-1;i++){
            nums1[i] = nums[i];
            nums2[i] = nums[i+1];
        }

        return max(maxRob(nums1),maxRob(nums2));
        
    }
};
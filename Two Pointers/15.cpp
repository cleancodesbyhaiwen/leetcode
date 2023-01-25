class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        if(nums.size() < 3){
            return result;
        }
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        for(int i = 0;i < n-2;i++){
            
            if(nums[i] > 0){
                break;
            }
            
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j+1] == nums[j]){
                        j++;
                    }
                    j++;
                    while(j < k && nums[k-1] == nums[k]){
                        k--;
                    }
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
            
        }
        return result;
        
    }
};
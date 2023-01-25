class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        
        int target = 0;
        for(int i = 0;i < nums.size();i++){
            target += nums[i];
        }
        if(target % 2 != 0){
            return false;
        }
        target /= 2;
        
        unordered_set<int> dp;
        dp.insert(0);
        
        for(int i = 0;i < nums.size();i++){
            unordered_set<int> newDp;
            for(auto it = dp.begin();it != dp.end();it++){
                if(*it + nums[i] == target){
                    return true;
                }
                newDp.insert(*it);
                newDp.insert(*it + nums[i]);
            }
            dp = newDp;
        }
        return false;
    }
};
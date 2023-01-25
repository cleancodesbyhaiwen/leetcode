class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        int complement = 0;
        int i = 0;
        
        for(i;i < nums.size();i++){
            complement = target - nums[i];
            if(m.find(complement) != m.end()){
                break;
            }
            m[nums[i]] = i;
        }
        return {m[complement], i};
    }
};
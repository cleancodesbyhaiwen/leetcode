class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for(int i = 0;i < nums.size();i++){
            s.insert(nums[i]);
        }
        
        int result = 0;
        
        for(auto it = s.begin();it != s.end();it++){
            int curr = *it;
            if (s.find(curr - 1) != s.end()) {
                continue;
            }            
            int currLen = 1;
            while(s.find(curr + 1) != s.end()){
                currLen++;
                curr++;
            }
            result = max(result, currLen);
        }
        return result;
       
    }
};
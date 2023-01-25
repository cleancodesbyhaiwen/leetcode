class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furtherest = 0;
        int last = nums.size() - 1;
        
        for(int i = 0;i < nums.size();i++){
            if(i > furtherest){
                return false;
            }
            furtherest = max(furtherest, i + nums[i]);
            if(furtherest >= last){
                break;
            }
        }
        return true;        
    }
};


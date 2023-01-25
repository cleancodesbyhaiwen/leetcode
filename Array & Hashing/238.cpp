class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> result(n, 1);
        
        int prevProduct= 1;
        
        for(int i = 0;i < n;i++){
            result[i] = prevProduct;
            prevProduct = prevProduct*nums[i];
        }
        
        int afterProduct = 1;
        for(int i = n-1;i >= 0;i--){
            result[i] = result[i]*afterProduct;
            afterProduct = afterProduct * nums[i];
        }
        
        return result;
        
    }
};
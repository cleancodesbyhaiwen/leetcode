class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() <= 2){
            return 0;
        }
        
        int result = 0;
        int max = -1;
        int maxAddr = 0;
        
        for(int i = 0;i < height.size();i++){
            if(height[i] > max)
            {
                max = height[i];
                maxAddr = i;
            }
        }
        
        for(int left = 0;left < maxAddr;left++){
            for(int i = left + 1;i <= maxAddr;i++){
                if(height[i] < height[left]){
                    result += (height[left] - height[i]);
                }
                else{
                    left = i;
                }
            }
        }
        
        for(int right = height.size()-1;right > maxAddr;right--){
            for(int i = right - 1;i >= maxAddr;i--){
                if(height[i] < height[right]){
                    result += (height[right] - height[i]);
                }
                else{
                    right = i;
                }
            }
        }
        
        return result;
    }
};
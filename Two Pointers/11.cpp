class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int result = 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right){
            int curr = (right-left)*min(height[left],height[right]);
            
            result = max(curr,result);
            
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};
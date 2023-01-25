class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        
        int left = 1;
        int right = 0;
        
        for(int i = 0;i < n;i++){
            right = max(right, piles[i]);
        }
        
        int result = right;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            long long int hours = 0;
            
            for(int i = 0;i < n;i++){
                hours += ceil((double) piles[i]/mid);
            }
            if(hours <= h){
                result = min(mid, result);
                right = mid - 1;
            }
            else if(hours > h){
                left = mid + 1;
            }
        }
        return result;
    }
};
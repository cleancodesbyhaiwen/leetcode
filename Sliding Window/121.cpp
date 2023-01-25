class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int result = 0;
        int left = 0;
        
        for(int right = 1;right < prices.size();right++){
            if(prices[left] > prices[right]){
                left = right;
            }
            result = max(result, prices[right] - prices[left]);
        }
        return result;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int minValue = prices[0];
        int result = 0;
        
        for(int i = 1;i < prices.size();i++){
            minValue = min(minValue, prices[i]);
            result = max(result, prices[i]-minValue);
        }
        return result;
    }
};
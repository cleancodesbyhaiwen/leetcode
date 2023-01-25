class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int hold = INT_MIN;
        int sold = 0;
        int rest = 0;
        for(int i = 0;i < prices.size();i++){
            int tmpHold = hold;
            hold = max(hold, rest-prices[i]);
            rest = max(rest, sold);
            sold = tmpHold+prices[i];
        }
        return max(rest, sold);
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int overall = 0;
        for(int i = 0;i < gas.size();i++){
            overall += (gas[i] - cost[i]);
        }
        if(overall < 0){
            return -1;
        }
        
        
        int n = gas.size();
        int total = 0;
        int result = 0;
        
        for(int i = 0;i < n;i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                result = i + 1;
            }
        }
        return result;
    }
};
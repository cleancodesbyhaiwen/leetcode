class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> waitDays(temperatures.size());
        
        stack<int> stk;
        
        for(int i = 0;i < temperatures.size();i++){
            
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                
                int index = stk.top();
                stk.pop();
                waitDays[index] = i - index;
            } 
            
            stk.push(i);
        }
        
        return waitDays;
        
    }
};
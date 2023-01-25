class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> stk;
        
        int index = 0;

        for(int i = 0;i < pushed.size();i++){
            stk.push(pushed[i]);
            
            while(!stk.empty() && popped[index] == stk.top()){
                stk.pop();
                index++;
            }
        }
        
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() % 2 == 1){
            return false;
        }
        
        stack<char> stk;
        
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            if(c == '('){
                stk.push(c);
            }
            else if(c == '{'){
                stk.push(c);
            }
            else if(c == '['){
                stk.push(c);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                char top = stk.top();
                if(top == '(' && c == ')' || top == '[' && c == ']' || top == '{' && c == '}'){
                    stk.pop();
                }
                else{
                    return false;
                }
                
            }
        }
        
        return stk.empty();
        
    }
};
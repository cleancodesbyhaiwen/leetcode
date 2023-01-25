class Solution {
public:
    int calculate(string s) {

        int res = 0;
        
        int sign = 1;
        
        int length = s.length();
        
        stack<int> stk;
        
        for(int i = 0;i < length;i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                long value = ch - '0';
                while(i + 1 < length && s[i + 1] >= '0' && s[i+1] <= '9'){
                    value = value*10 + s[i+1] - '0';
                    i++;
                }
                res += sign*value;
            }
            else if(ch == '+'){
                sign = 1;
            }
            else if(ch == '-'){
                sign = -1;
            }
            else if(ch == '('){
                stk.push(res);
                res = 0;
                stk.push(sign);
                sign = 1;
            }
            else if(ch == ')'){
                int savedSign = stk.top();
                stk.pop();
                int savedRes = stk.top();
                stk.pop();
                res = savedRes + savedSign * res;
            }
        }
        return res;
    }
};
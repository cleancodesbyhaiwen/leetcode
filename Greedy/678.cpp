class Solution {
public:
    bool checkValidString(string s) {
        
        int count1 = 0;  // count * as left parenthesis
        int count2 = 0;  // count * as right parenthesis
        
        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                count1++;
                count2++;
            }
            else if(s[i] == ')'){
                count1--;
                count2--;
            }
            else{
                count1++;
                count2--;
            }
            if(count1 < 0){
                return false;
            }
            if(count2 < 0){
                count2 = 0;
            }
        }
        if(count1 == 0 || count2 == 0){
            return true;
        }
        return false;
    }
};
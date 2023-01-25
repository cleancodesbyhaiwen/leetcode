class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        if(digits[digits.size()-1] < 9){
            digits[digits.size()-1]++;
        }
        else{
            int index = digits.size()-1;
            while(digits[index] == 9){
                digits[index] = 0;
                index--;
                if(index < 0){
                    break;
                }
            }
            if(index == -1){
                vector<int>new_vec(digits.size()+1, 0);
                new_vec[0] = 1;
                return new_vec;
            }
            else{
                digits[index]++;
            }
            
        }
        return digits;
    }
};
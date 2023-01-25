class Solution {
public:
    int reverse(int x) {
        
        
        vector<int> num;
        int index = 0;
        long result = 0;
        
        // Getting the array storing the digits of the int
        while(x != 0){
            num.push_back(x - (x / 10) * 10);
            x = x / 10;
            index++;
        }
        // Converting the array of digits back to int
        for(int i = 0;i < num.size();i++){
            result = result + num[i] * pow(10, num.size() - i -1);
        }
        
        if(result < -pow(2,31) || result > pow(2,31)){
            return 0;
        }
        return result;
    }
};
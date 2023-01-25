class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0){
            return false;
        }
        if(x == 0){
            return true;
        }
        
        vector<int> vec(10);
        
        int i = 0;
        while(x > 0)
        {
            int temp = x;
            x  = x / 10;
            vec[i] = temp - x*10;
            i++;
        }

        vec.resize(i);
        for(int i = 0;i < vec.size()/2 + 1;i++)
        {
            if(vec[i] != vec[vec.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};
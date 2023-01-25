class Solution {
public:
    
    void expand(string s, int i, int j, int &maxLen, int &maxBegin){
        while(i >= 0 && j <= s.size()-1 && s[i]==s[j]){
            i--;
            j++;
        }
        if(j-i-1>maxLen){
            maxLen = j-i-1;
            maxBegin = i+1;
        }
        
    }

    string longestPalindrome(string s) {
        
        int maxLen = 1;
        int maxBegin = 0;
        
        for(int i = 0;i < s.size()-1;i++){
            expand(s,i,i,maxLen,maxBegin);
            expand(s,i,i+1,maxLen,maxBegin);
        }
        
        return s.substr(maxBegin, maxLen);
        
    }
};
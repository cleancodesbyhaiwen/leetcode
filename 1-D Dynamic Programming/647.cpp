class Solution {
public:
    void expand(string s, int i, int j, int &count){
        while(i >= 0 && j <= s.size()-1 && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
    }
    
    
    int countSubstrings(string s) {
        
        int count = 0;
        
        for(int i = 0;i < s.size()-1;i++){
            expand(s, i, i,count);
            expand(s,i,i+1,count);
        }
        expand(s,s.size()-1,s.size()-1,count);
        return count;
        
    }
};
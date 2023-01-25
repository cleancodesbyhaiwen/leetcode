class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m;
        
        for(int i = 0;i < t.size();i++){
            m[t[i]]++;
        }
        
        int i = 0;
        int j = 0;
        
        int minLen = INT_MAX;
        int minBegin = 0;
        
        int count = t.size();
        
        while(j < s.size()){
            if(m[s[j]] > 0){
                count--;
            }
            m[s[j]]--;
            
            j++;
            
            while(count == 0){
                if(j - i < minLen){
                    minLen = j - i;
                    minBegin = i;
                }
                m[s[i]]++;
                if(m[s[i]] > 0){
                    count++;
                }
                i++;
            }
        }
        if(minLen != INT_MAX){
            return s.substr(minBegin, minLen);
        }
        return ""; 
    }
};
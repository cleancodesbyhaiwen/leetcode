class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()){
            return false;
        }
        
        unordered_map<char, int> m_s;
        unordered_map<char, int> m_t;
        
        for(int i = 0;i < s.size();i++){
            m_s[s[i]]++;
            m_t[t[i]]++;
        }
        
        if(m_s != m_t){
            return false;
        }
        return true;
        
    }
};
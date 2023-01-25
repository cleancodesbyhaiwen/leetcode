class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        vector<int> count(26);
        
        int result = 0;
        int maxCount = 0;
        
        int right = 0;
        int left = 0;
        
        while(right < s.size()){
            count[s[right]-'A']++;
            maxCount = max(maxCount, count[s[right]-'A']);
            if(right - left + 1 - maxCount > k){
                count[s[left]-'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result; 
    }
};
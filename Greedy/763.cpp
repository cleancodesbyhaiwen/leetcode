class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> m;
        
        for(int i = 0;i < s.size();i++){
            m[s[i]] = i;
        }
        
        int partition = 0;
        int prevPartition = -1;
        vector<int> result;
        
        for(int i = 0;i < s.size();i++){
            partition = max(partition, m[s[i]]);
            if(i == partition){
                result.push_back(partition-prevPartition);
                prevPartition = partition;
            }
        }
        return result;
    }
};
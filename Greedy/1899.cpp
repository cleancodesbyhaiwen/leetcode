class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        set<vector<int>> s;
        for(int i = 0;i < triplets.size();i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                s.insert(triplets[i]);
            }
        }
        
        bool first = false;
        bool second = false;
        bool third = false;
        
        for(auto it = s.begin();it != s.end();it++){
            if((*it)[0] == target[0]){
                first = true;
            }
            if((*it)[1] == target[1]){
                second = true;
            }
            if((*it)[2] == target[2]){
                third = true;
            }
        }
        return (first && second && third);
        
    }
};
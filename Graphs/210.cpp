class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, int> m;
        for(int i = 0;i < numCourses;i++){
            m[i] = 0;
        }
        for(int i = 0;i < prerequisites.size();i++){
            m[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(m[i] == 0){
                q.push(i);
            }
        }
        
        int index = 0;
        vector<int> result;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            index++;
            for(int i = 0;i < prerequisites.size();i++){
                if(prerequisites[i][1] == curr){
                    m[prerequisites[i][0]]--;
                    if(m[prerequisites[i][0]] == 0){
                        q.push(prerequisites[i][0]);
                    }
                }
            }
        }
        if(index != numCourses){
            return {};
        }
        return result;
    }
};
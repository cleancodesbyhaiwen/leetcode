class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> m;
        
        for(int i = 0;i < prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        unordered_set<int> visited;
        
        for(int i = 0;i < numCourses;i++){
            if(!dfs(i, m, visited)){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int currCourse, unordered_map<int, vector<int>>& m, unordered_set<int>& visited){
        
        if(visited.find(currCourse) != visited.end()){
            return false;
        }
        
        if(m[currCourse].empty()){
            return true;
        }
        visited.insert(currCourse);     
        for(int i = 0;i < m[currCourse].size();i++){
            if(!dfs(m[currCourse][i], m, visited)){
                return false;
            }
        }
        m[currCourse].clear();
        visited.erase(currCourse);
        return true;
    }
};
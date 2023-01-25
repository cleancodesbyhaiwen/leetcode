class Solution {
public:
    
    
    int bfs(vector<int> root, vector<vector<int>> grid, set<vector<int>>& visited){
        
        int size = 0;
        queue<vector<int>> q;
        q.push(root);
        visited.insert(root);
        size++;
        
        const vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            for(const auto& e : directions){
                vector<int> neighbor = {curr[0]+e[0],curr[1]+e[1]};
                if(neighbor[0] >= 0 && neighbor[1] >= 0 && neighbor[0] < grid.size() &&
                   neighbor[1] < grid[0].size() && grid[neighbor[0]][neighbor[1]] == 1 && 
                   visited.find(neighbor) == visited.end()){
                    q.push(neighbor);
                    visited.insert(neighbor);
                    size++;
                }
            }
        }
        return size;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        set<vector<int>> visited;
        int result = 0;
        
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1 && visited.find({i,j}) == visited.end()){
                    int size = bfs({i,j}, grid, visited);
                    result = max(result, size);
                }
            }
        }
        return result;
    }
};
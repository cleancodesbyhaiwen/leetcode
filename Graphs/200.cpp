class Solution {
public:
    void dfs(vector<int> root, set<vector<int>> &visited, vector<vector<char>> grid){
        queue<vector<int>> q;
        visited.insert(root);
        q.push(root);
        
        const vector<vector<int>> directions = {{0,1} , {0,-1}, {1,0}, {-1,0}};
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            for(const auto& e : directions){
                vector<int> neighbor = {cur[0] + e[0], cur[1] + e[1]};
                if(neighbor[0] >= 0 && neighbor[1] >= 0 && neighbor[0] < grid.size() && neighbor[1] < grid[0].size() &&
                  grid[neighbor[0]][neighbor[1]] == '1' && visited.find(neighbor) == visited.end()){
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty()){
            return 0;
        }
        
        int islands = 0;
        set<vector<int>> visited;
        
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j< grid[0].size();j++){
                if(grid[i][j] == '1' && visited.find({i,j}) == visited.end()){
                    dfs({i,j}, visited, grid);
                    islands++;
                }
            }
        }
        
        
        return islands;
        
    }
    
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        result = bfs(grid);
        return result;
    }
    
    int bfs(vector<vector<int>>& grid){
        int timer = 0;
        int freshCount = 0;   
        
        queue<pair<int, int>> q; // {row, col}
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }  
        
        if(freshCount == 0)
            return 0;
        
        vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};  
        
        while(!q.empty()){
            vector<pair<int,int>> currRound;
            while(!q.empty()){
                currRound.push_back(q.front());
                q.pop();
            }

            for(auto pos : currRound){
                for(auto dir : directions){
                    int row = pos.first+dir.first;
                    int col = pos.second+dir.second;
                    if(row >= 0 && col >= 0 && row <= grid.size() - 1 && 
                       col <= grid[0].size() - 1 && grid[row][col] == 1){
                        q.push({row,col});
                        if(grid[row][col] == 1){
                            grid[row][col] = 2;
                            freshCount--;
                        }
                    }
                }
            }
            timer++;
            if(freshCount < 1){
                return timer;
            }
        }        
        return -1;
    }
};
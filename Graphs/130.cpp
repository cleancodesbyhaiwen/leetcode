class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i < 0 || i > m-1 || j < 0 || j > n-1 || board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'T';
        dfs(board, i-1, j, m, n);
        dfs(board, i+1, j, m, n);
        dfs(board, i, j-1, m, n);
        dfs(board, i, j+1, m, n);
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<pair<int, int>> border;
        
        for(int i = 0;i < m;i++){
            border.push_back({i, 0});
            border.push_back({i, n-1});
        }
        for(int j = 0;j < n;j++){
            border.push_back({0, j});
            border.push_back({m-1, j});
        }
        
        for(int i = 0;i < border.size();i++){
            dfs(board, border[i].first, border[i].second, m, n);
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
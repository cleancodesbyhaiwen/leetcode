class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0;i < m;i++){
            for(int j =0;j < n;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index, int m, int n){
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }
        
        if(index == word.size() - 1){
            return true;
        }
        
        board[i][j] = '!';
        
        
        if(dfs(board, word, i+1, j, index+1,m,n) || dfs(board, word, i, j+1, index+1,m,n)
          || dfs(board, word, i-1, j, index+1,m,n) || dfs(board, word, i, j-1, index+1,m,n)){
            return true;
        }
        
        board[i][j] = word[index];
        return false;
    }
};
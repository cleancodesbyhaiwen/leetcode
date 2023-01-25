class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> s;
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(s.find(board[i][j]) != s.end()){
                    return false;
                }
                else{
                    s.insert(board[i][j]);
                }
            }
            s.clear();
        }
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[j][i] == '.'){
                    continue;
                }
                if(s.find(board[j][i]) != s.end()){
                    return false;
                }
                else{
                    s.insert(board[j][i]);
                }
                
            }
            s.clear();
        }        
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int m = i; m < i + 3; m++) {
                    for (int n = j; n < j + 3; n++) {
                        if (board[m][n] == '.') {
                            continue;
                        }
                        auto it = s.find(board[m][n]);
                        if (it != s.end()) {
                            return false;
                        } else {
                            s.insert(board[m][n]);
                        }
                    }
                }
                s.clear();
            }
        }
        return true;
    }
};
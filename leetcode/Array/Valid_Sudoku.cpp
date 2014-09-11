class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> row_vec(9);
        vector<bool> column_vec(9);
        vector<bool> block_vec(9);
        
        for (int i = 0; i < 9; ++i) {
            reset(row_vec);
            reset(column_vec);
            reset(block_vec);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0' - 1;
                    if (row_vec[idx]) {
                        return false;
                    } else {
                        row_vec[idx] = true;
                    }
                }
                
                if (board[j][i] != '.') {
                    int idx = board[j][i] - '0' - 1;
                    if (column_vec[idx]) {
                        return false;
                    } else {
                        column_vec[idx] = true;
                    }
                }
                
                if (board[i/3 *3 + j/3][(i%3)*3 + j%3] != '.') {
                    int idx = board[i/3 *3 + j/3][(i%3)*3 + j%3] - '0' - 1;
                    if (block_vec[idx]) {
                        return false;
                    } else {
                        block_vec[idx] = true;
                    }
                }
            }
        }
        
        return true;
    }
    
    void reset(vector<bool> &vec) {
        for (int i = 0; i < vec.size(); ++i) {
            vec[i] = false;
        }
    }
};

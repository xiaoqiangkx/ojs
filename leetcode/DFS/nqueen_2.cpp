#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;
        vector<vector<char> > board(n, vector<char>(n, '.'));
        fill(board, 0, total);
        return total;
    }
    
    void fill(vector<vector<char> > &board, int line, int &total) {
        if (line == board.size()) {
            ++total;
            return;
        }
        
        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board, line, col)) {
                board[line][col] = 'Q';
                fill(board, line + 1, total);
                board[line][col] = '.';
            }
        }
    }
    
    bool isValid(vector<vector<char> > &board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if ('Q' == board[i][col]) {
                return false;
            }
            
            int left_col = col - (row - i);
            int right_col = col + (row - i);
            
            if (left_col >= 0 && 'Q' == board[row][left_col]) {
                return false;
            }
            
            if (right_col < board.size() && 'Q' == board[row][right_col]) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
	Solution s;
	cout << s.totalNQueens(9) << endl;
	return 0;
}

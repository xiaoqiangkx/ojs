class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = tmp;
            }
        }
        
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = tmp;
            }
        }
    }
};

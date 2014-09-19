class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int st = 0;
        int ed = m * n - 1;
        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (target < matrix[mid / n][mid % n]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return false;
    }
};

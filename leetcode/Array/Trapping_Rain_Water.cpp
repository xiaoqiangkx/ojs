class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) {
            return 0;
        }
        
        int max_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[max_idx]) {
                max_idx = i;
            }
        }
        
        int sum = 0;
        int cur_max = A[0];
        for (int i = 1; i < max_idx; ++i) {
            if (cur_max <= A[i]) {
                cur_max = A[i];
            } else {
                sum += (cur_max - A[i]);
            }
        }
        
        cur_max = A[n - 1];
        for (int i = n - 2; i > max_idx; --i) {
            if (cur_max <= A[i]) {
                cur_max = A[i];
            } else {
                sum += (cur_max - A[i]);
            }
        }
        
        return sum;
    }
};

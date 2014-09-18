class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idx = m + n - 1;
        int a_idx = m - 1;
        int b_idx = n - 1;
        while (a_idx >= 0 && b_idx >= 0) {
            if (A[a_idx] > B[b_idx]) {
                A[idx--] = A[a_idx--];
            } else {
                A[idx--] = B[b_idx--];
            }
        }
        
        while (b_idx >= 0) {
            A[idx--] = B[b_idx--];
        }
    }
};

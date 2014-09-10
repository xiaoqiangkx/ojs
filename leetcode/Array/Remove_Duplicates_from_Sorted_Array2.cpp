class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) {
            return n;
        }
        
        const int MAX = 2;
        unsigned len = 1;
        unsigned cnt = 1;
        for (unsigned idx = 1; idx < n; ++idx) {
            if (A[idx] != A[len - 1]) {
                cnt = 1;
                A[len++] = A[idx];
            } else if (cnt < MAX) {
                ++cnt;
                A[len++] = A[idx];
            }
        }
        
        return len;
    }
};
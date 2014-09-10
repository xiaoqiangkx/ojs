class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) {   // 判断特殊条件, 后面的循环考虑大于1的情况，简洁。
            return n;
        }
        
        unsigned len = 1;
        for (unsigned idx = 1; idx < n; ++idx) {
            if (A[len - 1] != A[idx]) {
                A[len++] = A[idx];
            }
        }
        
        return len;
    }
    
    int removeDuplicates(int A[], int n) {
        return distance(A, unique(A, A + n));
    }
};
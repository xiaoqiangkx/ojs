class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 0) {
            return (findKth(A, m, B, n, (m + n) / 2) +
                findKth(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        } else {
            return findKth(A, m, B, n, (m + n) / 2 + 1);
        }
    }
    
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findKth(B, n, A, m, k);
        }
        
        if (0 == m) {
            return B[k - 1];
        }
        
        if (1 == k) {
            return A[0] < B[0] ? A[0] : B[0];
        }
        
        int mk = min(m, k/2);
        int nk = k - mk;
        
        if (A[mk - 1] <= B[nk - 1]) {
            return findKth(A + mk, m - mk, B, n, k - mk);
        } else {
            return findKth(A, m, B + nk, n - nk, k - nk);
        }
    }
};
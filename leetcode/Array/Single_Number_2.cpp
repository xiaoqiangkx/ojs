class Solution {
public:
    int singleNumber(int A[], int n) {
        int accur1 = 0;
        int accur2 = 0;
        int accur3 = 0;
        
        for (int i = 0; i < n; ++i) {
            accur3 = accur2 & A[i];
            accur2 = (accur1 & A[i]) | (accur2 & ~A[i]);
            accur1 = (accur1 ^ A[i]) & ~accur3;
        }
        
        return accur1;
    }
};

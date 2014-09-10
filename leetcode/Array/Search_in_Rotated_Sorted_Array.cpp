class Solution {
public:
    int search(int A[], int n, int target) {
        int st = 0;
        int ed = n - 1;
        
        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            if (A[mid] == target) {
                return mid;
            }
            
            if (A[st] < A[mid]) {
                if (target >= A[st] && target < A[mid]) {
                    ed = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (target > A[mid] && target <= A[ed]) {
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
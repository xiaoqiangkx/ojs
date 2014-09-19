class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int st = 0;
        int ed = n - 1;
        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (target < A[mid]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return st;
    }
};

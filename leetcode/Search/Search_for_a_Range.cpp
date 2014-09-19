class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int st = 0;
        int ed = n - 1;
        int target_idx = -1;
        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            if (target == A[mid]) {
                target_idx = mid;
                break;
            } else if (target < A[mid]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        if (target_idx == -1) {
            return vector<int>(2, -1);
        }
        
        int start = target_idx;
        int end = target_idx;
        
        for (int i = target_idx - 1; i >= 0; --i) {
            if (target == A[i]) {
                --start;
            } else {
                break;
            }
        }
        
        for (int i = target_idx + 1; i < n; ++i) {
            if (target == A[i]) {
                ++end;
            } else {
                break;
            }
        }
        
        vector<int> result(2);
        result[0] = start;
        result[1] = end;
        return result;
    }
};

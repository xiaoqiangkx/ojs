class Solution {
public:
    void sortColors(int A[], int n) {
        int colors[3] = { 0 };
        
        for (int i = 0; i < n; ++i) {
            colors[A[i]]++;
        }
        
        int idx = 0;
        for (int i = 0; i < 3;) {
            if (colors[i] == 0) {
                ++i;
                continue;
            } else {
                A[idx++] = i;
                colors[i]--;
            }
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        int pos = -1;
        for (int i = len - 1; i > 0; --i) {
            if (num[i-1] < num[i]) {
                pos = i - 1;
                break;
            }
        }
        
        if (pos == -1) {
            for (int i = 0; i < len / 2; ++i) {
                swap(num, i, len - 1 - i);
            }
        } else {
            for (int i = pos + 1; i < len; ++i) {
                if (i == len - 1 || num[i + 1] <= num[pos]) {
                    swap(num, pos, i);
                    break;
                }
            }
            
            for (int i = pos + 1; i < pos + 1 + (len - 1 - pos) / 2; ++i) {
                swap(num, i, pos + 1 + len - 1 - i);
            }
        }
    }
    
    void swap(vector<int> &num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
};

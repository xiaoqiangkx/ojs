class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int st = -1;
        int len = num.size();
        
        for (int i = len - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                st = i;
                break;
            }
        }
        
        if (st != -1) {
            int last = st + 1;
            for (int i = st + 2; i < len; i++) {
                if (num[i] > num[st]) {
                    last = i;
                }
            }
            
            swap(num[st], num[last]);
            reverse(num, st + 1, len - 1);
        } else {
            reverse(num, 0, len - 1);
        }
    }
    
    void reverse(vector<int> &num, int st, int ed) {
        while (st < ed) {
            swap(num[st], num[ed]);
            ++st;
            --ed;
        }
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        if (b.size() > a.size()) {
            a.swap(b);
        }
        
        int a_idx = a.size() - 1;
        int b_idx = b.size() - 1;
        int add = 0;
        
        while (a_idx >= 0 && b_idx >= 0) {
            int sum = a[a_idx] - '0' + b[b_idx] - '0' + add;
            a[a_idx] = sum % 2 + '0';
            add = sum / 2;
            --a_idx;
            --b_idx;
        }
        
        while (add != 0) {
            if (a_idx < 0) {
                a.insert(a.begin(), add + '0');
                add = 0;
            } else {
                int sum = a[a_idx] - '0' + add;
                a[a_idx] = sum % 2 + '0';
                add = sum / 2;
                --a_idx;
            }
        }
        
        return a;
    }
};

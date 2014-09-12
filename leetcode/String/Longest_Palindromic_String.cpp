class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        
        int longest_st = 0;
        int longest_ed = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int st = i;
            int ed = i;
            while (st >= 0 && ed <= s.size() - 1) {
                if (s[st] == s[ed]) {
                    --st;
                    ++ed;
                } else {
                    break;
                }
            }
            
            st++;
            ed--;
            
            if (ed - st + 1 > longest_ed - longest_st + 1) {
                longest_st = st;
                longest_ed = ed;
            }
        }
        
        for (int i = 0; i < s.size() - 1; ++i) {
            int st = i;
            int ed = i + 1;
            if (s[st] != s[ed]) {
                continue;
            }
            while (st >= 0 && ed <= s.size() - 1) {
                if (s[st] == s[ed]) {
                    --st;
                    ++ed;
                } else {
                    break;
                }
            }
            
            st++;
            ed--;
            
            if (ed - st + 1 > longest_ed - longest_st + 1) {
                longest_st = st;
                longest_ed = ed;
            }
        }
        
        return s.substr(longest_st, longest_ed - longest_st + 1);
    }
};

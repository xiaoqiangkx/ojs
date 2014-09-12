class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        
        int st = 0;
        int ed = len - 1;
        
        while (st < ed) {
            if (!isalnum(s[st])) {
                ++st;
                continue;
            }
            
            if (!isalnum(s[ed])) {
                --ed;
                continue;
            }
            
            if (isalpha(s[st]) && isalpha(s[ed])) {
                int gap = s[st] - s[ed];
                if (gap == 'a' - 'A' || gap == 'A' - 'a' || gap == 0) {
                    ++st;
                    --ed;
                    continue;
                } else {
                    return false;
                }
            } else if (s[st] == s[ed]) {
                ++st;
                --ed;
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
};

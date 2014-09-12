class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s) {
            if (*s != ' ') {
                ++len;
            } else if (*(s + 1) && * (s + 1) != ' ') {
                len = 0;
            }
            
            ++s;
        }
        
        return len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        int pos = -1;
        stack<int> left;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else {
                if (left.empty()) {
                    pos = i;
                } else {
                    left.pop();
                    if (!left.empty()) {
                        longest = max(longest, i - left.top());
                    } else {
                        longest = max(longest, i - pos);
                    }
                }

            }
        }
        
        return longest;
    }
};

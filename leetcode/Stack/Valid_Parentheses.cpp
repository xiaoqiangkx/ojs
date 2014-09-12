class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                char_stack.push(s[i]);
            } else {
                if (char_stack.empty()) {
                    return false;
                }
                
                char c = char_stack.top();
                char_stack.pop();
                if (s[i] == ']' && c == '[' ||
                    s[i] == '}' && c == '{' ||
                    s[i] == ')' && c == '(') {
                        continue;
                    } else {
                        return false;
                    }
            }
        }
        
        return char_stack.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        string left = "([{";
        string right = ")]}";
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (left.find(c) != string::npos) {
                char_stack.push(s[i]);
            } else {
                if (char_stack.empty() || char_stack.top() != left[right.find(c)]) {
                    return false;
                } else {
                    char_stack.pop();
                }
            }
        }
        
        return char_stack.empty();
    }
};

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ss;
        string s = "+-*/";
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].size() == 1 && s.find(tokens[i][0]) != string::npos) {
                int rhs = ss.top();
                ss.pop();
                int lhs = ss.top();
                ss.pop();
                
                if (tokens[i] == "+") {
                    int sum = lhs + rhs;
                    ss.push(sum);
                } else if (tokens[i] == "-") {
                    int result = lhs - rhs;
                    ss.push(result);
                } else if (tokens[i] == "*") {
                    int result = lhs * rhs;
                    ss.push(result);
                } else if (tokens[i] == "/") {
                    int result = lhs / rhs;
                    ss.push(result);
                } 
            } else {
                ss.push(atoi(tokens[i].c_str()));
            }
        }
        
        return ss.top();
    }
};

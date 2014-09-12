class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int result = 0;
        stack<int> s;
        height.push_back(0);
        int st = 0;
        int pos = -1;
        while (st < height.size()) {
            if (s.empty() || height[st] > height[s.top()]) {
                s.push(st++);
            } else {
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp] * (s.empty() ? st : st - s.top() - 1));
            }
        }
        
        return result;
    }
};

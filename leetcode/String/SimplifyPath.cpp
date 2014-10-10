#include <string>
#include <algorithm>
#include <iostream>
using namespace std; 

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        int len = path.size();
        int idx = len - 1;
        string tmp;
        int dot_cnt = 0;
        int char_cnt = 0;
        int prev_cnt = 0;
        
        while (idx >= 0) {
            if ('/' == path[idx]) {
                if (dot_cnt == 2 && char_cnt == 2) {
                    ++prev_cnt;
                } else if (char_cnt == 1 && dot_cnt == 0 || char_cnt >= 2) {
                    if (prev_cnt == 0) {
                        tmp.push_back('/');
                        result += tmp;
                    } else {
                        --prev_cnt;
                    }
                }
                
                cout << tmp << endl;
                --idx;
                dot_cnt = 0;
                char_cnt = 0;
                tmp.clear();
            } else {
                if ('.' == path[idx]) {
                    ++dot_cnt;
                }
                ++char_cnt;
                tmp.push_back(path[idx]);
                --idx;
            }
        }
        
        reverse(result.begin(), result.end());
        if (result.size() == 0) {
            result.push_back('/');
        }
        
        return result;
    }
};

int main() {
	Solution s;
	string path = "/abc/...";
	cout << s.simplifyPath(path) << endl;
	return 0;
}

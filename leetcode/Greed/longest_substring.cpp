#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int max_len;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (char_set.find(s[i]) == char_set.end()) {
                char_set.insert(s[i]);
            } else {
                max_len = max(max_len, i - cur);
                cout << "cur=" << cur << ",max_len=" << max_len << endl;
                for (; cur < i; ++cur) {
                    if (s[cur] != s[i]) {
                        char_set.erase(s[cur]);
                    } else {
                        break;
                    }
                }
                
                ++cur;
            }
        }
        
        int last_len = s.size() - cur;
        max_len = max(max_len, last_len);
        return max_len;
    }
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
	return 0;
}

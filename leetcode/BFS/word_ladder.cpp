#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>
using namespace std; 

class Solution {
public:
    int ladderLength(const string &start, const string &end, unordered_set<string> &dict) {
        int depth = 0;
        queue<string> str_que;
        queue<string> swap_que;
        str_que.push(start);
        
        while (!str_que.empty()) {
        		//static int cnt = 0;
        		//++cnt;
            while(!str_que.empty()) {
                string str = str_que.front();
                str_que.pop();
                
                if (str == end) {
                    return depth + 1;
                }
                
                for (int i = 0; i < str.size(); ++i) {
                	char raw_char = str[i];
                  for (char c = 'a'; c <= 'z'; ++c) {
                    str[i] = c;
                    unordered_set<string>::iterator iter = dict.find(str);
                    if (iter != dict.end()) {
                   // 		cout << cnt << ":str=" << str << endl;
                        swap_que.push(str);
                        dict.erase(iter);
                    }
                	}
                	str[i] = raw_char;
							  }

            }
            str_que.swap(swap_que);
            ++depth;
        }
    
        return 0;
    }
};

int main() {
	unordered_set<string> dict = {"hot", "dog", "dot"};
	Solution s;
	cout << s.ladderLength("hot", "dog", dict) << endl;
	return 0;
}

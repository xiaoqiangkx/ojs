#include <string>
#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    string minWindow(string S, string T) {
        const int ASCII_NUM = 256;
        vector<int> expected_cnt(ASCII_NUM, 0);
        vector<int> appear_cnt(ASCII_NUM, 0);
        for (int i = 0; i < T.size(); ++i) {
            expected_cnt[T[i]]++;
        }
        
        int start = 0;
        int min_len = INT_MAX;
        int appear = 0;
        
        for (int i = 0; i < S.size(); ++i) {
            if (expected_cnt[S[i]] > 0) {
                ++appear_cnt[S[i]];
            
                if (appear_cnt[S[i]] <= expected_cnt[S[i]]) {
                    ++appear;
                }
            
            		cout << "i=" << i << ",appear=" << appear << endl;
                if (appear == T.size()) {
                	for (int i = 0; i < ASCII_NUM; ++i) {
                	if (appear_cnt[i] > 0) {
                		cout << char(i) << ",cnt=" << appear_cnt[i] << endl;
                	}
                }
                    while (appear_cnt[S[start]] > expected_cnt[S[start]] ||
                    expected_cnt[S[start]] == 0) {
                    		cout << S[start] << endl;
                        if (expected_cnt[S[start]] != 0) {
                            --appear_cnt[S[start]];
                        }
                        ++start;
                    }
                    
                    min_len = min(min_len, i - start + 1);
                    cout << "i=" << i << ",start=" << start << ",min_len=" << min_len << endl; 
                }
            }
        }
        
        return min_len == INT_MAX ? "" : string(S, start, min_len);
        
    }
};

int main() {
	Solution s;
	cout << s.minWindow("cabwefgewcwaefgcf", "cae") << endl;
	return 0;
}

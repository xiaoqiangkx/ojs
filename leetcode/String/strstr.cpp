#include <cstring>
#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (needle == NULL) {
            return haystack;
        }
        
        if (haystack == NULL) {
            return NULL;
        }
        
        int hay_len = strlen(haystack);
        int need_len = strlen(needle);
        
        if (need_len == 0) {
            return haystack;
        }
        
        if (hay_len == 0) {
            return NULL;
        }
        
        vector<int> table(need_len + 1);
        make_table(needle, table);
        
        int hay_idx = 0;
        int need_idx = 0;
        
        while (hay_idx < hay_len && need_idx < need_len) {
            if (haystack[hay_idx] == needle[need_idx]) {
                ++hay_idx;
                ++need_idx;
                
                if (need_idx == need_len) {
                    return haystack + hay_idx - need_idx;
                }
            } else {
                hay_idx -= table[need_idx];
                need_idx = 0;
            }
        }
        
        return NULL;
    }
    
    void make_table(char *needle, vector<int> &table) {
        table[0] = -1;
        table[1] = 0;
        
        for (int i = 2; i <= table.size() - 1; ++i) {
            int cur = table[i - 1];
            while (cur >= 0) {
                if (needle[cur] == needle[i - 1]) {
                    table[i] = cur + 1;
                    break;
                } else {
                    cur = table[cur];
                }
            }
            
            if (cur < 0) {
                table[i] = 0;
            }
        }
    }
};

int main() {
	Solution s;
	s.strStr(NULL, NULL);
	return 0;
}

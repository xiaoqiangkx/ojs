Restore IP Addresses
======================================


题目描述
==================

给定一个字符串S, 找出最小的区间包含字符串T中所有字符.

举例:

S = "ADOBECODEBANC"
T = "ABC"

返回:

Minimum window is "BANC".

分析与解法
==================


解法一
------------------

使用`map\<int, vector\<int\> \>`构建字符串T的映射表, 每次替换int数组中的最小值或者-1值, 每次cnt达到最大值时, 更新即可.

### 复杂度计算

最坏情况可以达到0(nm).

### 代码

```
class Solution {
public:
    string minWindow(string S, string T) {
        
        int cnt = 0;
        map<char, vector<int> > char_index_map;
        
        // 使用map来存储数组
        for (int i=0; i<T.size(); i++) {
            if (char_index_map.find(T[i]) == char_index_map.end()) {
                char_index_map[T[i]] = vector<int>();
            } 
            
            char_index_map[T[i]].push_back(-1);
        }
        
        int start_idx = -1, end_idx = -1;
        int min_range = INT_MAX;
        for (int i=0; i<S.size(); i++) {
            if (char_index_map.find(S[i]) == char_index_map.end()) 
                continue;
            else {
                if (test_insert_and_full(char_index_map[S[i]], i)) {
                    cnt++;
                }
            }
            
            if (cnt == T.size()) {
                int temp_start = INT_MAX;
                int temp_end = INT_MIN;
                
                for (map<char, vector<int> >::iterator iter = char_index_map.begin(); iter != char_index_map.end(); iter++) {
                    vector<int> &data = iter->second;
                    for (int i=0; i<data.size(); i++) {
                        if (data[i] < temp_start) temp_start = data[i];
                        if (data[i] > temp_end) temp_end = data[i];
                    }
                }
                
                if (temp_start != INT_MAX && (temp_end - temp_start + 1) < min_range) {
                    min_range = temp_end - temp_start + 1;
                    start_idx = temp_start;
                    end_idx = temp_end;
                }
                
            }
        }
        
        if (min_range == INT_MAX) 
            return "";
        else 
            return S.substr(start_idx, end_idx - start_idx + 1);
    }
    
private:
    // find the smallest and insert, if the smallest is -1 and is the last one, return full firstly
    bool test_insert_and_full(vector<int> &ivec, int idx) {
        
        int min_idx = 0;
        
        for (int i=1; i<ivec.size(); i++) {
            if (ivec[i] < ivec[min_idx]) 
                min_idx = i;
        }
        
        bool result = false;
        if (ivec[min_idx] == -1 || min_idx == ivec.size()) result = true;
        
        ivec[min_idx] = idx;
        
        return result;
    }
};
```

### 结果   

Time Limit Exceeded 超时



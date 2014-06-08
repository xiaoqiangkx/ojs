Restore IP Addresses
======================================


题目描述
==================

给定一个表示IPV4地址的digit字符串, 返回所有可能的IP地址

举例:

**"25525511135"**

返回:

\["255.255.11.135", "255.255.111.35"\]  顺序不限


分析与解法
==================

第一印象是进行深度搜索, 当凑齐了4个0~255的数后, 返回一个结果.

解法一
------------------

### 复杂度计算


代码如下:

```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // 边界测试
        
        vector<string> collection;
        string temp;
        int depth = 0;
        int index_raw = 0;
        // 递归
        populate(s, index_raw, temp, collection, depth);
        return collection;
    }
    
private:
    void populate(const string &s, int index_raw, string &temp, vector<string> &collection, int depth) {
        // return when depth == 4
        if (depth == 4) {
            if (index_raw == s.size()) {
                collection.push_back(temp);
            }
            
            return;
        }
        
        // 加入1~3个数字进入
        int num_left_char = s.size() - index_raw;
        if (num_left_char >= 1) {
            append(temp, s, index_raw, 1);
            populate(s, index_raw + 1, temp, collection, depth+1);
            erase(temp, 1, depth);
        }
        
        if (num_left_char >= 2 && s[index_raw] != '0') {
            append(temp, s, index_raw, 2);
            populate(s, index_raw + 2, temp, collection, depth+1);
            erase(temp, 2, depth);
        }
        
        if (num_left_char >= 3 && s[index_raw] != '0') {
            int num = atoi(s.substr(index_raw, 3).c_str());
            if (num <= 255) {
                append(temp, s, index_raw, 3);
                populate(s, index_raw + 3, temp, collection, depth+1);
                erase(temp, 3, depth);
            }
        }
        
    }
    
    void append(string &temp, const string &s, int st, int len) {
        if (st == 0) {
            temp.insert(temp.size(), s, st, len);
        } else {
            temp.push_back('.');
            temp.insert(temp.size(), s, st, len);
        }
    }
    
    void erase(string &temp, int len, int depth) {
        if (depth == 0) {
            temp.erase(temp.size() - len, len);
        } else {
            temp.erase(temp.size() - len, len);
            temp.pop_back();
        }
    }
};
```


### 结果   

AC



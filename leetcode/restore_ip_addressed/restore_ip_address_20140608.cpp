#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
        
        cout << "depth=" << depth << ",index_raw=" << index_raw 
            << ",temp=" << temp << endl;
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
            cout << "size=" << temp.size() << ",erase(" << (temp.size() - len)
                << "," << len << ")" << endl;
            temp.erase(temp.size() - len, len);
        } else {
            cout << "size=" << temp.size() << ",erase(" << (temp.size() - len)
                << "," << len << ")" << endl;
            temp.erase(temp.size() - len, len);
            cout << "pop_back, depth=" << depth << endl;
            temp.pop_back();
        }
    }
};


int main() {
    Solution s;
    string data = "0000";
    vector<string> col = s.restoreIpAddresses(data);
    for (int i=0; i<col.size(); i++) {
        cout << col[i] << endl;
    }
    return 0;
}

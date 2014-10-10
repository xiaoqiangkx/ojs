#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> result;
        vector<int> vec;
        int index = 0;
        fill(s, index, vec, result);
        return result;
    }

private:
    void fill(const string &s, int index, vector<int> &vec, vector<string> &result) {
        if (index == s.size() || vec.size() == 4) {
            if (index == s.size() && vec.size() == 4) {
                string data = make_str(vec);
                result.push_back(data);
            }
            return;
        }
        
        for (int len = 1; len <= 3; ++len) {
            int num = getNext(s, index, len);
            cout << "index=" << index << ",len=" << len << ",num=" << num << endl;
            if (num != -1) {
                vec.push_back(num);
                index += len;
                fill(s, index, vec, result);
                index -= len;
                vec.pop_back();
            }
        }
    }
    
    string make_str(vector<int> &vec) {
        string result;
        result += int2str(vec[0]);
        for (int i = 1; i < vec.size(); ++i) {
            result.push_back('.');
            result += int2str(vec[i]);
        }
        
        return result;
    }
    
    string int2str(int num) {
        if (0 == num) {
            return "0";
        }
        
        string result;
        while (num > 0) {
            result.push_back(num % 10 + '0');
            num /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    int getNext(const string &s, int index, int len) {
        if (len > 3) {
            return -1;
        }
        
        if (len + index - 1 >= s.size()) {
            return -1;
        }
        
        if (len >= 2 && '0' == s[index] && '0' == s[index + 1]) {
            return -1;
        }
        
        int total = 0;
        for (int i = 0; i < len; ++i) {
            total = total * 10 + (s[index + i] - '0');
        }
        
        if (total > 255) {
            return -1;
        }
        return total;
    }
};

int main() {
	Solution s;
	s.restoreIpAddresses("0000");
	return 0;
}

#include <vector>
#include <string>
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string data[] = {" ", "xx", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};
        
        vector<string> result;
        string tmp;
        int index = 0;
        fill(digits, data, index, tmp, result);
        return result;
    }
    
    void fill(const string &digits, string data[], int index, string &tmp,
        vector<string> result) {
        if (tmp.size() == digits.size()) {
        		cout << "test" << endl;
            result.push_back(tmp);
            cout << result.size() << endl;
            return;
        }        
        
        int digit = digits[index] - '0';
        if (1 == digit) {
            return;
        }
        
        for (int i = 0; i < data[digit].size(); ++i) {
            tmp.push_back(data[digit][i]);
            fill(digits, data, index + 1, tmp, result);
            tmp.resize(tmp.size() - 1);
        }
    }

};

int main() {
	string digits = "";
	Solution s;
	s.letterCombinations(digits);
	return 0;
}

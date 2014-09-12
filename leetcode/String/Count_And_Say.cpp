class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while (--n) {
            s = getNext(s);
        }
        
        return s;
    }
    
    string getNext(const string & s) {
        string tmp;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c) {
                ++cnt;
            } else {
                fillNum(tmp, cnt, c);
                cnt = 1;
                c = s[i];
            }
        }
        
        fillNum(tmp, cnt, c);
        return tmp;
    }
    
    void fillNum(string &s, int cnt, char c) {
        string tmp = int_2_s(cnt);
        s += tmp;
        s.push_back(c);
    }
    
    string int_2_s(int num) {
        if (num == 0) {
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
};

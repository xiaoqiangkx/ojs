#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0) {
            return s2 == s3;
        } else if (s2.size() == 0) {
            return s1 == s3;
        }
        
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<int> > memo(len1+1, vector<int>(len2+1, -1));
        
        return isValid(s1, s2, s3, 0, 0, memo);
    }
    
private:
    bool isValid(string &s1, string &s2, string &s3, int cnt1, int cnt2, vector<vector<int> > &memo) {
        if (cnt1 == s1.size() && cnt2 == s2.size() && cnt1 + cnt2 == s3.size()) {
            memo[cnt1][cnt2] = 1;
            return true;
        }
        
        bool result = false;
        
        if (cnt1 != s1.size()) {
            if (memo[cnt1+1][cnt2] == -1) {
                if (s1[cnt1] == s3[cnt1+cnt2]) {
                    result = result || isValid(s1, s2, s3, cnt1+1, cnt2, memo);
                } else {
                    memo[cnt1+1][cnt2] = 0;                
                }
            } else {
                result = result || memo[cnt1+1][cnt2];
            }
        }
        
        if (cnt2 != s2.size()) {
            if (memo[cnt1][cnt2+1] == -1) {
                if (s2[cnt2] == s3[cnt1+cnt2]) {
                    result = result || isValid(s1, s2, s3, cnt1, cnt2+1, memo);
                } else {
                    memo[cnt1][cnt2+1] = 0;                
                }
            } else {
                result = result || memo[cnt1][cnt2+1];
            }
        }
        
        memo[cnt1][cnt2] = result ? 1 : 0;
        return result;
    }
};

int main() {
    Solution s;
    string s1("a");
    string s2("b");
    string s3("ab");
    s.isInterleave(s1, s2, s3);
    return 0;
}

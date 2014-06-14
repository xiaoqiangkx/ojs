Restore IP Addresses
======================================


题目描述
==================

给定字符串s1, s2, 判断s3是否是s1,s2按顺序插入产生的.

举例:

s1 = "aabcc",
s2 = "dbbca",

返回:

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


分析与解法
==================

类似于s1, s2逐个取值生成s3的过程, 与**两个有序数组求并集**很像, 需要使用动态规划的算法即可.

解法一
------------------

2014-06-14

使用memo(s1.size(), s2.size())的二维数组记录值. 1, 0, -1分别表示可行, 不可行和未访问. 终止条件为s1和s2所有元素用尽. 迭代条件为判断memo(i+1, )和memo(, j+1)是否可行.同时每轮需要给memo(i, j)赋值.


### 复杂度计算

最多迭代O(mn)次.简单的递归为O(2^n)次

### 边界条件

判断s1和s2非空, 且s1和s2长度之和为s3


### 代码

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

### 结果   

AC



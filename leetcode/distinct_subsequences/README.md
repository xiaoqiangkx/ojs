Distinct Subsequences 求不同的子串个数
======================================


题目描述
==================

给定两个字符串A和字符串B. 判断字符串A是否是字符串B的子串(删除字符串中0到`size(B)-1`个字符均为子串), 并判断B中子串A的出现次数.

比如:
String A : "rabbit"
String B : "rabbbit"

答案是3. 由于删除String B中的任何一个b均可以得到子串A.


分析与解法
==================

题意十分明了, 要求判断String A是否出现在String B中, 并计算出现次数.



解法一
------------------

最直观也是最简单的思路是, 找出String B中所有长度与A相等的子串. 类似于**DFS中的组合问题**, 即从String B取出中`size(A)`个字符. 由于B中所有的子串都已经取出, 算法一定正确, 无需证明.

### 复杂度计算

当String A="ab", String B="aaaaaaab"这种情况时, 需要进行`size(B)\*size(B)`次比较.

代码如下:

```
class Solution {
public:
    int numDistinct(string S, string T) {
        int size_str = S.size();
        int size_substr = T.size();
        
        if (size_substr > size_str || size_substr == 0) return 0;
        
        string temp;
        temp.reserve(size_substr);
        
        int result = 0;
        int str_index = 0;
        calculate(S, T, temp, str_index, result);     // temp存放当前的值, 当temp的长度等于T时, result++, 否则继续T取出等于S元素即可
        
        return result;
    }
    
private:
    void calculate (const string &str, const string &sub_str, string &temp, int str_index, int &result) {
        if (temp.size() == sub_str.size()) {
            result++;
            return;
        }
        
        for (int i=str_index; i<str.size(); i++) {
            int index = temp.size();
            if (sub_str[index] == str[i]) { // 两个元素相等
                temp.push_back(str[i]);
                calculate(str, sub_str, temp, i+1, result);                
                temp.pop_back();
            }
        }
    }    
};
```


### 结果   

大数据无法通过, 超时


解法二
------------------

**ad-hoc思路**: 以"aab"和"aaabaaaab"为例, 子串计数的多样性来源于存在多个连续的大于"aa"长度的"aaa"或者"aaaa", 所以问题关键在于寻找"aab"中每个字母段"aa"和"b"的匹配情况, 最后采取递归的思路解决.

### 举例与证明

由于每轮都把前面可能匹配的情况指出, 所以必然正确. 

### 复杂度

不好计算, 两种极端情况, 字符串A重复次数多,例如"aaaaa", 那么循环多递归少, 当字符串完全不重复, 那么循环少递归多. 复杂度不太坏


### 代码

```
class Solution {
public:
    int numDistinct(string S, string T) {
        int size_str = S.size();
        int size_substr = T.size();
        
        if (size_substr > size_str || size_substr == 0) return 0;
        
        int str_index = 0;
        int substr_index = 0;
        int result = calculate(S, T, str_index, substr_index);     // temp存放当前的值, 当temp的长度等于T时, result++, 否则继续T取出等于S元素即可
        
        return result;
    }
    
private:
    int calculate (const string &str, const string &substr, int str_index, int substr_index) {
        if (substr_index == substr.size()) {
            return 1;
        } else if (str_index == str.size()) {
            return 0;
        }
        
        // c_cnt must be greater than 1
        char c = substr[substr_index];
        int substr_cnt = 1;
        for (int i=substr_index + 1; i<substr.size(); i++) {
            if (substr[i] != c)
                break;
            substr_cnt++;                
        }
        
        int total = 0;
        
        int str_cnt = 0;
        for (int j=str_index; j<str.size(); j++) {
            if (substr[j] == c) {
                str_cnt++;
                continue;
            }
            
            if (str_cnt >= substr_cnt) {
                total += calculate(str, substr, str_index + str_cnt, substr_index + substr_cnt) * compose(str_cnt, substr_cnt);
            }
         
            str_cnt = 0;   
        }
        
        if (str_cnt >= substr_cnt) {
            total += calculate(str, substr, str_index + str_cnt, substr_index + substr_cnt) * compose(str_cnt, substr_cnt) ;
        }
        
        return total;
        
    }    
    
    int compose(int n, int k) {
        int result = 1;
        while (k-- > 0) {
            result *= n--;
        }
        
        return result;
    }
};
```

### 结果

大数据无法通过, 超时

举一反三
==================


更多相关
==================

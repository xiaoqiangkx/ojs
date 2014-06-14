Restore IP Addresses
======================================


题目描述
==================

找到第k个排列的数

举例:

n = 3, k = 2, 找到`\[1,2,3\]`中排列为2的组合


返回:

"132"



分析与解法
==================

AD-HOC 类似于进制转换的题, 找到进制数并使用一个数组保存已使用的数即可.

解法一
------------------

### 复杂度计算

O(n)

### 代码


```
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial_array(n+1);
        populate_array(factorial_array);
        
        vector<bool> isVisited_array(n, false); // default to be all zero
        
        if (k > factorial_array[n]) return "";
        
        string result;
        for (int i=0; i<n; i++) {
            int index = (k - 1) / factorial_array[n-1-i];   // 此处是细节
            k -= index * factorial_array[n-1-i];
            
            int num = set_zero(isVisited_array, index+1);
            result.push_back(num + '0');
        }
        
        return result;
    }
    
    int set_zero(vector<bool> &isVisited_array, int cnt) {
        int total = 0;
        for (int i=0; i<isVisited_array.size(); i++) {
            if (isVisited_array[i] == false) {
                total++;
            }
            
            if (cnt == total) {
                isVisited_array[i] = true;
                return i+1;
            }
        }
        
        return 0;
    }
    
    void populate_array(vector<int> &factorial_array) {
        int total = 1;
        for (int i=0; i<factorial_array.size(); i++) {
            factorial_array[i] = total;
            total *= (i+1);
        }
    }
};
```

### 结果   

AC



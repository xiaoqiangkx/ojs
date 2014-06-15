Restore IP Addresses
======================================


题目描述
==================

找到未排序数组中的两个数, 其和等于target. 要求返回两个数的索引.

举例:

 numbers={2, 11, 7, 15}, target=9

返回:

index1 = 1, index2 = 3

分析与解法
==================

使用一个数组来记录索引值, 然后对数组使用quick-sort.

解法一
------------------

### 复杂度计算

O(nlogn)

### 代码

```
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> index_vec(numbers.size());
        
        for (int i=0; i<index_vec.size(); i++) {
            index_vec[i] = i;
        }
        
        // quick sort
        partition_sort(numbers, 0, numbers.size()-1, index_vec);
        
        int i = 0;
        int j = numbers.size() - 1;
        
        vector<int> result(2);
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                result.push_back(min(index_vec[i], index_vec[j]) + 1);
                result.push_back(max(index_vec[i], index_vec[j]) + 1);
                break;
            } else if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            }
            
        }
        
        return result;
    }
    
private:

    void swap(vector<int> &data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    
    void partition_sort(vector<int> &data, int st, int ed, vector<int> &index_vec) {
        if (st >= ed) return;
        
        int k = partition(data, st, ed, index_vec);
        partition_sort(data, st, k-1, index_vec);
        partition_sort(data, k+1, ed, index_vec);
    }
    
    int partition(vector<int> &data, int st, int ed, vector<int> &index_vec) {
        int i = st;
        int j = st+1;
        while (j <= ed) {
            if (data[j] >= data[st]) {
                j++;
                continue;
            } else if (data[j] < data[st]) {
                swap(data, i+1, j);
                swap(index_vec, i+1, j);
                i++;
                j++;
            }
        }
        
        swap(data, i, st);
        swap(index_vec, i, st);
        return i;
    }
};
```

### 结果   

AC



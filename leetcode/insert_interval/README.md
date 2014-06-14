Restore IP Addresses
======================================


题目描述
==================

合并给定区间的问题.

举例:

`\[1,3\], \[6,9\]`加入`\[2,5\]`


返回:

`\[1,5\], \[6, 9\]`

分析与解法
==================

首先应该进行排序, 按照start和end进行排序即可.

解法一
------------------

### 复杂度计算

排序需要O(nlogn)的复杂度, 需要is\_merge和insert\_new两个变量来区分是否插入了newInterval.

### 代码

```
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct Sort_Interval {
        bool operator()(const Interval &lhs, const Interval &rhs) {
            return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
        }
    };
    
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        sort(intervals.begin(), intervals.end(), Sort_Interval());
        
        vector<Interval> result;
        
        bool is_merge = false;
        bool insert_new = false;
        
        int i = 0;
        for (i=0; i<intervals.size(); i++) {
            
            if (is_merge) {
                if (isOverlap(newInterval, intervals[i])) {
                    merge(newInterval, intervals[i]);
                    continue;
                } else {
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                    is_merge = false;
                    insert_new = true;
                }
            } else {
                if (isLeftSide(newInterval, intervals[i]) && !insert_new) {
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                    insert_new = true;
                } else if (isOverlap(newInterval, intervals[i])) {
                    merge(newInterval, intervals[i]);
                    continue;
                } else {
                     result.push_back(intervals[i]);
                }
            }
        }
        
        if (!insert_new) result.push_back(newInterval);
        return result;
    }
    
private:
    bool isOverlap(Interval &lhs, Interval &rhs) {
        return (lhs.start <= rhs.start && lhs.end >= rhs.start) || (lhs.start > rhs.start && lhs.start <= rhs.end); // 注意是<=和>=
    }
    
    bool isLeftSide(Interval &lhs, Interval &rhs) {
        return (lhs.start < rhs.start && lhs.end < rhs.start);
    }
    
    void merge(Interval &lhs, Interval &rhs) {
        if (lhs.start <= rhs.start && lhs.end >= rhs.start) {   // lhs有半部分重叠
            lhs.end = max(rhs.end, lhs.end);
        } else {
            lhs.start = rhs.start;
            lhs.end = max(rhs.end, lhs.end);
        }
    }
};
```

### 结果   

AC



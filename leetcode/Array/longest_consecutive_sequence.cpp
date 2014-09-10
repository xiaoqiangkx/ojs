class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> numSet;
        for (int i = 0; i < num.size(); ++i) {
            numSet.insert(num[i]);
        }
        
        int longest = 0;
        for (int i = 0; i < num.size(); ++i) {
            int curNum = num[i];
            if (numSet.find(curNum) == numSet.end()) {
                continue;
            }
            
            int count = 1;
            while (1) {
                unordered_set<int>::iterator it = numSet.find(++curNum);
                if (it != numSet.end()) {
                    ++count;
                    numSet.erase(it);
                } else {
                    break;
                }
            }
            
            curNum = num[i];
            while (1) {
                unordered_set<int>::iterator it = numSet.find(--curNum);
                if (it != numSet.end()) {
                    ++count;
                    numSet.erase(it);
                } else {
                    break;
                }
            }
            
            if (count > longest) {
                longest = count;
            }
        }
        
        return longest;
    }
};



class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        int len = num.size();
        
        for (int i1 = 0; i1 <= len - 4; ++i1) {
            if (i1 > 0 && num[i1] == num[i1 - 1]) {
                continue;
            }
            
            for (int i4 = len - 1; i4 >= 3; --i4) {
                if (i4 < len - 1 && num[i4] == num[i4 + 1]) {
                    continue;
                }
                
                int st = i1 + 1;
                int ed = i4 - 1;
                
                while (st < ed) {
                    if (st > i1 + 1 && num[st] == num[st - 1]) {
                        ++st;
                        continue;
                    }
                    
                    if (ed < i4 - 1 && num[ed] == num[ed + 1]) {
                        --ed;
                        continue;
                    }
                    
                    int gap = num[i1] + num[st] + num[ed] + num[i4] - target;
                    
                    if (gap > 0) {
                        --ed;
                    } else if (gap < 0) {
                        ++st;
                    } else {
                        vector<int> tmp(4);
                        tmp[0] = num[i1];
                        tmp[1] = num[st];
                        tmp[2] = num[ed];
                        tmp[3] = num[i4];
                        result.push_back(tmp);
                        ++st;
                        --ed;
                    }
                }
            }
        }
        
        return result;
    }
};
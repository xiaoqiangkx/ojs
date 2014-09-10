class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int result = INT_MAX;
        int ret_sum = 0;
        
        for (int i = 0; i < num.size(); ++i) {
            int st = i + 1;
            int ed = num.size() - 1;
            
            while (st < ed) {
                int gap = num[i] + num[st] + num[ed] - target;
                int abs_num = (gap >= 0 ? gap : -gap);
                
                if (abs_num < result) {
                    result = abs_num;
                    ret_sum = gap + target;
                }
                
                if (gap > 0) {
                    --ed;
                } else if (gap < 0) {
                    ++st;
                } else {
                    return ret_sum;
                }
            }
        }
        
        return ret_sum;
    }
};

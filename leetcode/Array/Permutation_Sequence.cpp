class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> stairs(n, 1);
        
        int tmp = 1;
        for (int i = 1; i < n; ++i) {
            stairs[i] = tmp;
            tmp *= (i + 1);
        }
        
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        
        while (k != 1) {
            int stair = stairs[n - result.size() - 1];
            int idx = (k - 1) / stair + 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != -1) {
                    ++cnt;
                }
                
                if (cnt == idx) {
                    result.push_back('0' + nums[i]);
                    nums[i] = -1;
                    k -= (idx - 1) * stair;
                    break;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != -1) {
                result.push_back('0' + nums[i]);
            }
        }
        
        return result;
    }
};

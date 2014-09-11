class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        vector<int> nums;
        int idx = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);
            if (sum < 0) {
                nums.push_back(sum);
                sum = 0;
                idx = i + 1;
            }
        }
        
        if (sum + accumulate(nums.begin(), nums.end(), 0) >= 0) {
            return idx;
        } else {
            return -1;
        }
    }
};

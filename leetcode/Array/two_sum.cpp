class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mapper;
        
        for (unsigned i = 0; i < numbers.size(); ++i) {
            mapper[numbers[i]] = i + 1;
        }
        
        vector<int> result(2);
        for (unsigned i = 0; i < numbers.size(); ++i) {
            map<int, int>::iterator it = mapper.find(target - numbers[i]);
            if (it != mapper.end() && it->second != i + 1) {
                result[0] = i + 1;
                result[1] = mapper[target - numbers[i]];
                break;
            }
        }
        
        return result;
    }
};
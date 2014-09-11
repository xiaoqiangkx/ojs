class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        list<int> tmp_list;
        int add = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int num = (digits[i] + add) % 10;
            add = (digits[i] + add) / 10;
            tmp_list.push_front(num);
        }
        
        if (add != 0) {
            tmp_list.push_front(add);
        }
        
        vector<int> result(tmp_list.begin(), tmp_list.end());
        return result;
    }
};

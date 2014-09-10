#include <vector>
#include <algorithm>
using std::vector; 

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            
            int st = i + 1;
            int ed = num.size() - 1;
            
            while (st < ed) {
                int sum = num[i] + num[st] + num[ed];
                if (0 == sum) {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[st];
                    tmp[2] = num[ed];
                    result.push_back(tmp);
                    ++st;
                    --ed;
                    
                    while (st < ed && num[st] == num[st - 1]) {
                        ++st;
                    }
                    
                    while (st < ed && num[ed] == num[ed + 1]) {
                        --ed;
                    }
                } else if (0 < sum) {
                    --ed;
                } else {
                    ++st;
                }
            }
        }
        
        return result;
    }
};

int main() {
	int a[] = {-1, 0, 1, 2, -1, -4};
	vector<int> data(a, a + sizeof(a)/sizeof(int));
	Solution s;
	s.threeSum(data);
	return 0;
}

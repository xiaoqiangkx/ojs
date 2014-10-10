#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        
        cout << "num.size=" << (num.size() - 3) << endl;
        for (int i = 0; i < num.size() - 3; ++i) {
            cout << "enter" << endl;
						if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            
            for (int j = num.size() - 1; j >= 3; --j) {
                if (j < num.size() - 1 && num[j] == num[j + 1]) {
                    continue;
                }
                
                int st = i + 1;
                int ed = j - 1;
                
                while (st < ed) {
                    int sum = num[i] + num[j] + num[st] + num[ed];
                    
                    if (sum == target) {
                        vector<int> tmp(4, -1);
                        tmp[0] = num[i];
                        tmp[1] = num[st];
                        tmp[2] = num[ed];
                        tmp[3] = num[j];
                        
                        while (st < ed && tmp[1] == num[st]) {
                            ++st;
                        }
                        
                        while (st < ed && tmp[2] == num[ed]) {
                            --ed;
                        }
                        
                        result.push_back(tmp);
                    } else if (sum < target) {
                        ++st;
                    } else {
                        --ed;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
	Solution s;
	vector<int> num;
	s.fourSum(num, 0);
	return 0;
}

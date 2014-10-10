#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        int depth = 0;
        vector<int> tmp;
        sort(S.begin(), S.end());
        fill(S, depth, tmp, result);
        return result;
    }
    
    void fill(vector<int> &S, int depth, vector<int> &tmp, vector<vector<int> > &result) {
        result.push_back(tmp);
        
        for (int i = depth; i < S.size(); ++i) {
            tmp.push_back(S[i]);
            fill(S, depth + i, tmp, result);
            tmp.pop_back();
        }
    }
};

int main() {
	Solution s;
	int a[] = {3, 2, 1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > result = s.subsets(vec);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

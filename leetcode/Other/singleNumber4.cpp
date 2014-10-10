// each bit and accur in only one variable
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int accur1 = 0;
        int accur2 = 0;
        int accur3 = 0;
        int accur4 = 0;
        
        for (int i = 0; i < n; ++i) {
        		accur4 = accur3 & A[i];
            accur3 = (accur2 & A[i]) | (accur3 & ~A[i]) & ~accur4;
            accur2 = ((accur1 & A[i]) | (accur2 & ~A[i])) & ~accur3 & ~accur4;
            accur1 = (accur1 ^ A[i]) & ~accur3 & ~accur2 & ~accur4;
            accur4 = 0;
        }
        
        return accur2;
    }
};

int main() {
	int A[] = {4, 4, 335, 335, 335, 22, 22, 22, 22, 335, 3, 3, 3, 3, 1, 1, 1, 1};
	Solution s;
	cout << s.singleNumber(A, 6) << endl;
	return 0;
}

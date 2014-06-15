#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> index_vec(numbers.size());
        
        for (int i=0; i<index_vec.size(); i++) {
            index_vec[i] = i;
        }
        
        // bubble sort
        for (int i=0; i<numbers.size()-1; i++) {
            
            int min_index = i;
            for (int j=i+1; j<numbers.size(); j++) {
                if (numbers[j] < numbers[min_index]) {
                    min_index = j;
                }
            }
            
            swap(numbers, min_index, i);
            swap(index_vec, min_index, i);
        }
        
        int i = 0;
        int j = numbers.size() - 1;
        
        vector<int> result;
        cout << result.size() << endl;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                result.push_back(min(index_vec[i], index_vec[j]) + 1);
                result.push_back(max(index_vec[i], index_vec[j]) + 1);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        cout << result.size() << endl;
        
        return result;
    }
    
private:

    void swap(vector<int> &data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
};


int main() {
    int a[] = {0, 4, 3, 0};
    vector<int> ivec(a, a+4);
    Solution s;
    vector<int> result = s.twoSum(ivec, 0);
    cout << "success" << endl;
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

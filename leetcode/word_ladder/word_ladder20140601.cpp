#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <unordered_set>
using namespace std;

class Solution {
    typedef unordered_set<string>::iterator dict_iter_t;

    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
       if (start == end) return 1;

	   map<string, bool> isVisitedMap; 

       for (dict_iter_t iter = dict.begin(); iter != dict.end(); iter++) {
               isVisitedMap[*iter] = false;
       }
       
       vector<vector<string> > data;
       vector<string> temp;
       temp.push_back(start);

       populate(data, dict, start, end, temp, isVisitedMap);

       //cout << "size(data)=" << data.size() << endl;
       
       int min_path_len = INT_MAX;
       if (data.size() != 0) {
            for (int i=0; i<data.size(); i++) {
                if (data[i].size() < min_path_len) {
                     min_path_len = data[i].size();
                }
            }
       }

       return min_path_len == INT_MAX ? 0 : min_path_len;
  }

    private:
        void populate(vector<vector<string> > &data, unordered_set<string> &dict, string &start, string &end, vector<string> &temp, map<string, bool> &isVisitedMap) {
                if (compare_str(temp.back(), end) == 1) {
                    temp.push_back(end);
                    data.push_back(temp);
                    return;
                }

                for(dict_iter_t iter = dict.begin(); iter != dict.end(); iter++) {
                      if (isVisitedMap[*iter] == false && compare_str(*iter, temp.back()) == 1) {
                              temp.push_back(*iter);
                              isVisitedMap[*iter] = true;
                              populate(data, dict, start, end, temp, isVisitedMap);
                              temp.pop_back();
                              isVisitedMap[*iter] = false;
                      }
                }
        }

        int compare_str(const string &str1, const string &str2) {
                
                int cnt = 0;
                for (int i=0; i<str1.size(); i++) {
                    if (str1[i] != str2[i]) cnt++;
                }

                //cout << str1 << " " << str2 << " " << cnt << endl;
                return cnt;
        }

};


int main() {
    Solution s;
    string sarr[5] = {"hot","dot","dog","lot","log"};
    vector<string> data(sarr, sarr + 5);
    unordered_set<string> dict(data.begin(), data.end());
    string start = string("hit"), end = string("cog");
    int result = s.ladderLength(start, end, dict);
    cout << "result=" << result << endl;
    return 0;
}

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
       map<string, vector<string> > str_vec_map;

       for (dict_iter_t iter = dict.begin(); iter != dict.end(); iter++) {
               isVisitedMap[*iter] = false;
               vector<string> temp;
               for (dict_iter_t iter1 = dict.begin(); iter1 != dict.end(); iter1++) {
                       if (compare_str(*iter1, *iter) == 1) {
                               temp.push_back(*iter1);
                       }
               }

               str_vec_map[*iter] = temp;
       }
        
      vector<string> temp_vec;
      for (dict_iter_t iter1 = dict.begin(); iter1 != dict.end(); iter1++) {
          if (compare_str(*iter1, start) == 1) {
                  temp_vec.push_back(*iter1);
          }
       }

       str_vec_map[start] = temp_vec;
       
//       vector<vector<string> > data;
       vector<string> temp;
       temp.push_back(start);

       int min_path_len = INT_MAX;
       populate(dict, start, end, temp, isVisitedMap, min_path_len, str_vec_map);

       return min_path_len == INT_MAX ? 0 : min_path_len;
  }

    private:
        void populate(unordered_set<string> &dict, string &start, string &end, vector<string> &temp, map<string, bool> &isVisitedMap, int &max_path_len, map<string, vector<string> > &str_vec_map) {
                if (compare_str(temp.back(), end) == 1) {
                    temp.push_back(end);
                    if (temp.size() < max_path_len) max_path_len = temp.size();
                    return;
                }

                vector<string> &str_map_vec = str_vec_map[temp.back()]; 
                for(vector<string>::iterator iter = str_map_vec.begin(); iter != str_map_vec.end(); iter++) {
                      if (isVisitedMap[*iter] == false && compare_str(*iter, temp.back()) == 1) {
                              temp.push_back(*iter);
                              isVisitedMap[*iter] = true;
                              populate(dict, start, end, temp, isVisitedMap,  max_path_len, str_vec_map);
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

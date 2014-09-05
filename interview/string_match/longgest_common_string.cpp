#include <iostream>
#include <string>
using namespace std;

string Lcs(const string &text, const string &query) {
  string::size_type text_st = -1;
  string::size_type query_st = -1;
  string::size_type longest_len = 0;

  for (string::size_type idx = 0; idx < text.size(); ++idx) {
    string::size_type text_idx = idx;
    string::size_type query_idx = 0;

    string::size_type length = 0;
    while (text_idx < text.size() && query_idx < query.size()) {
      if (text[text_idx] == query[query_idx]) {
        ++length;
        
        if (length > longest_len) {
          longest_len = length;
          text_st = text_idx - longest_len + 1;
          query_st = query_idx - longest_len + 1;
        }
      } else {
        length = 0;
      }

      ++text_idx;
      ++query_idx;
    }
  }

    for (string::size_type idx = 0; idx < text.size(); ++idx) {
    string::size_type text_idx = 0;
    string::size_type query_idx = idx;

    string::size_type length = 0;
    while (text_idx < text.size() && query_idx < query.size()) {
      if (text[text_idx] == query[query_idx]) {
        ++length;
        
        if (length > longest_len) {
          longest_len = length;
          text_st = text_idx - longest_len + 1;
          query_st = query_idx - longest_len + 1;
        }
      } else {
        length = 0;
      }

      ++text_idx;
      ++query_idx;
    }
  }

  if (0 == longest_len) {
    return "";
  } else {
    return string(text, text_st, longest_len);
  }
}

void CheckResult(const string& text, const string &query, const string &result) {
  string ret_str = Lcs(text, query);
  cout << (ret_str == result) << ",expected=" << result << ", actually=" 
       << ret_str << endl;
}

int main() {
  CheckResult("dfadfabcafda", "abcde", "abc");
  return 0;
}

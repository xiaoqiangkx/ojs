#include <iostream>
#include <vector>
#include <string>
using namespace std;

// table��¼��i��Ԫ���ڵ��ǰ׺�� 
void MakeTable(const string &query, vector<int> &table) {
	// initialize
  table[0] = -1;
  table[1] = 0; 

  for (unsigned cnt = 2; cnt <= query.size(); ++cnt) {
    unsigned lastIdx = cnt - 1;
    while (table[lastIdx] >= 0) {
    	// table[lastIdx]��ʾ����������table[lastIdx]�պ�����һ��Ҫ�Ƚϵ�Ԫ�� 
      if (query[table[lastIdx]] == query[cnt - 1]) {
        table[cnt] = table[lastIdx] + 1;
        break;
      } else {
        lastIdx = table[lastIdx];
      }
    }
		
		// judge match or not 
		if (lastIdx == -1) {
			table[cnt] = 0;
		}
  }
}

void KmpString(const string &text, const string &query) {
  string::size_type text_size = text.size();
  string::size_type query_size = query.size();

  vector<int> table(query_size + 1);
  MakeTable(query, table);

  string::size_type text_idx = 0;
  string::size_type query_idx = 0;

  while (text_idx < text_size) {
    if (text[text_idx] == query[query_idx]) {
      ++text_idx;
      ++query_idx;

			// use query_size not query_size - 1
      if (query_idx == query_size) {
        query_idx = 0;
      }
    } else {
    	// traceback
      text_idx -= table[query_idx];
      query_idx = 0;
    }
  }
}

int main() {
  KmpString("abcabcabd", "abcabd");
  return 0;
}

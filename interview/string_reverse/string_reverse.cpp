#include <iostream>
#include <cctype>
#include <string>

void ReverseSentence(std::string &text) {
  std::string::size_type st = 0;
  std::string::size_type ed = text.size() - 1;

  while (ed >= 0) {
    if (isspace(text[ed])) {
      --ed;
    } else {
      break;
    }
  }

  while (st < ed) {
    char temp = text[st];
    text[st] = text[ed];
    text[ed] = temp;
    ++st;
    --ed;
  }
}

void CheckResult(const std::string &text, const std::string &result) {
	std::string raw = text;
  ReverseSentence(raw);
  std::cout << (raw == result) << ",expected=" << result << ",actually=" << raw << std::endl;
}

int main() {
  CheckResult("abc", "cba");
  CheckResult("abc   ", "cba   ");
  CheckResult("   abc", "cba   ");
  return 0;
}

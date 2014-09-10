#include <iostream>
#include <cctype>
#include <string>

void ReverseSentence(std::string &text) {
  std::string::size_type st;
  std::string::size_type ed;

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
  }
}

void CheckResult(std::string &text, std::string &result) {
  ReverseSentence(text);
  std::cout << (text == result) << ",expected=" << result << "actually=" << text << std::endl;
}

int main() {
  CheckResult("abc", "cba");
  CheckResult("abc   ", "cba   ");
  CheckResult("   abc", "   cba");
  return 0;
}
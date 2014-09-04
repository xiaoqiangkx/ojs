#include <cctype>
#include <iostream>
#include <string>

int CountWords(const std::string &text) {
	bool encounter_alpha = false;
  bool encounter_dash = false;

  int word_count = 0;

  for (std::string::size_type index = 0; index < text.size(); ++index) {
    if (isalpha(text[index])) {
      encounter_alpha = true;
    } else if ('-' == text[index] && !encounter_dash) {
      encounter_dash = true;
    } else if (isspace(text[index]) && encounter_alpha) {
      ++word_count;
      encounter_alpha = false;
      encounter_dash = false;
    } else {
      encounter_dash = false;
      encounter_alpha = false;
      
      // 一旦发现非法字符后，需要跳过后面连续的非空字符 
      while (index < text.size()) {
        if (isspace(text[index])) {
          break;
        } else {
          ++index;
          continue;
        }
      }
    }
  }

  if (encounter_alpha == true) {
    ++word_count;
  }

  return word_count;
}

void CheckResult(const std::string text, int target) {
	int result = CountWords(text);
  std::cout << ((result == target) ? "True" : "False") << ", " << text << ", expected: " << target << ", result: " << result << std::endl;
}

int main() {
  CheckResult("", 0);
  CheckResult("abc123", 0);
  CheckResult("123abc", 0);
  CheckResult("abc--", 0);
  CheckResult("abc--abc", 0);
  CheckResult("--abc", 0);
  CheckResult("abc1--abc", 0);

  CheckResult("abc", 1);
  CheckResult("abc-a", 1);
  CheckResult("abc ", 1);
  CheckResult("abc-a ", 1);
  
  CheckResult("abc def 123 agd1-ddf adg-- abc de", 4);  
  return 0;
}

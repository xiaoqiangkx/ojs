统计单词
===============

题目说明
---------------
给定一个string文本，统计里面的单词个数。（注：一个破折号的算单词，二个以上破折号连接的不算单词）

测试用例
---------------

- 问题1：单词只包含大小写字吧。破折号在字母中间才是合法的吧？   

用例如下

    // 错误用例
	CheckResult("", 0);
    CheckResult("abc123", 0);
    CheckResult("123abc", 0);
    CheckResult("abc--", 0);
    CheckResult("abc--abc", 0);
    CheckResult("--abc", 0);
    CheckResult("abc1--abc", 0);

	// 基本用例
    CheckResult("abc", 1);
    CheckResult("abc-a", 1);
    CheckResult("abc ", 1);
    CheckResult("abc-a ", 1);

	// 复杂用例
    CheckResult("abc def 123 agd1-ddf adg-- abc de", 4);

思路
--------------

本质上是一个状态机问题。通过encounterDash和encounterAlpha两个变量来表示。

- 状态0：初次状态。
- 状态1：碰到单词后进入此状态。
- 状态2：状态1条件下首次碰到`-`
- 状态3：状态2条件下碰到单词进入此状态
- 状态4：进入此状态后直接跳过所有的非空单词即可。进入状态0.

**注：**结束后需要判断是否在状态1或者状态3。

重要代码
----------
代码1：

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
	  
	  while (index < text.size()) {
	    if (isspace(text[index])) {
	      break;
	    } else {
	      ++index;
	      continue;
	    }
	  }
	}

代码2：

	if (encounter_alpha == true) {
	  ++word_count;
	}
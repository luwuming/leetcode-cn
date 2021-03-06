
//////////////////////////////////////////////////////////////////////////
//int longestSubstring(string s, int k) {
//	//特殊情况
//	if (s.size() == 0)
//		return 0;
//
//	//count记录s中26个字母出现的次数
//	//count[0]-->a的次数  count[1]-->b的次数...以此类推
//	vector<int>count(26, 0);
//
//
//	//numOfLessThanK记录有多少种字母的数量大于0小于k
//	int numOfLessThanK = 0;
//	for (char &x : s) {
//		//增加了一个新的字母，则可能的小于k的字母种类+1
//		if (count[x - 'a'] == 0)
//			numOfLessThanK++;
//
//		count[x - 'a']++;
//
//		//有一种字母达到了数量k,则小于k的字母种类-1
//		if (count[x - 'a'] == k)
//			numOfLessThanK--;
//	}
//	//不存在小于数量k的字母，则说明s已经符合要求
//	if (numOfLessThanK == 0)
//		return s.size();
//
//	//pre记录上s中上一个出现次数>=k的索引位置
//	//cur用来记录当前遍历到的位置
//	//ans用来存最大长度
//	int pre = 0, cur = 0;
//	int ans = 0;
//	while (cur < s.size()) {
//		//当前cur位置上对应的字母数量小于k
//		if (count[s[cur] - 'a'] < k) {
//			//递归计算[pre,cur-1]区间上的子串ss对应的答案
//			string ss = s.substr(pre, cur - pre);
//			// 如果子串长度小于等于当前的候补答案ans
//			// 则没必要计算这个子串
//			if (ss.size() > ans) {
//				ans = max(ans, longestSubstring(ss, k));
//			}
//
//			int end = cur;
//			//end为从cur位置开始下一个出现字母次数大于k的位置
//			while (end < s.size() && count[s[end] - 'a'] < k)
//				end++;
//			//[cur,end-1]这个区间的字母出现次数全部小于k
//			//所以下一个可能的子串开始位置pre=end
//			pre = end;
//			cur = end;
//		}
//		else
//			cur++;
//	}
//	//前面while循环退出是cur=s.size()
//	//因为循环是每到一个cur位置上对应的字母数量小于k
//	//时就计算前一个子串。。
//	//所以有可能最后一个子串[pre,cur-1]没计算过
//	if (pre < s.size()) {
//		string ss = s.substr(pre, cur - pre);
//		//同样，如果子串长度小于等于当前的候补答案ans
//		//则没必要递归计算
//		if (ss.size() > ans) {
//			ans = max(ans, longestSubstring(ss, k));
//		}
//	}
//
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
int longestSubstring(string s, int k)
{
	int ans = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		int counts[26] = { 0 };
		auto check = [&counts, &k]()
		{
			for (int i = 0; i < 26; i++)
			{
				if (counts[i] != 0 && counts[i] < k) return false;
			}
			return true;
		};

		if (i != 0 && s[i] == s[i - 1]) continue;
		for (size_t j = i; j < s.length(); j++)
		{
			counts[s[j] - 'a']++;
			if (ans >= j - i + 1) continue;
			ans = check() ? max(ans, (int)(j - i + 1)) : ans;
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
	return longestSubstring(s,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}


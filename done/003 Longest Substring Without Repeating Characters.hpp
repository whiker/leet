#include "util.h"

/*
	string s = "";
	s += "abcdefghijklmnopqrstuvwxyz";
	s += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	s += "0123456789!\"#$&'()*+,-./:";
	s += ";<=>?@[\\]^_`{|}~ ";

	Solution solu;
	cout << solu.lengthOfLongestSubstring(s) << endl;
*/

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		const char *inp = s.data();
		int n = s.length();
		if (n == 0) return 0;

		// 记录最长长度和结束于前一位置的最长长度
		int max_length = 1, length = 1;
		int from = 0;

		bool flag[130];
		memset(flag, 0, 130);
		flag[inp[0]] = 1;

		for (int curr = 1; curr < n; ++curr)
		{
			if (flag[inp[curr]] == 0)
			{
				if (length+1 > max_length)
				{
					flag[inp[curr]] = 1;
					++length;
					max_length = length;
					continue;
				}
			}

			memset(flag, 0, 130);
			length = 0;
			for (int i = curr; i >= 0; --i)
			{
				if (flag[inp[i]] == 1)
					break;
				flag[inp[i]] = 1;
				++length;
			}
		}

		return max_length;
	}
};
